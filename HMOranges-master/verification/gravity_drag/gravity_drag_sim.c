//
// Created by akern on 02/04/2020.
//

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else

#include <CL/cl.h>

#endif

#include <stdio.h>
#include "../../util/clUtils/clUtils.h"
#include "../../util/particleUtils/particleUtils.h"
#include "../../tests/run_tests/run_tests.h"
#include "../../util/simUtils/simUtils.h"
#include "../../sims/simRunner/simRunner.h"
#include <math.h>
#include <malloc.h>

#define MAX_SOURCE_SIZE (0x100000)
#define VERBOSE FALSE
#define LOG_DATA TRUE

//char prefix[50];
char *prefix = "gravity_drag";

particle *hparticles;
cl_ulong NUMPART = 1;

cl_double density = 997;
cl_double particle_diameter = 0.05;
cl_double fluid_viscosity = 0.1;

cl_double initial_vel_x = 0;

cl_float timestep;
cl_float sim_length;
cl_float log_step;

cl_float domain_length;

cl_context context;
cl_device_id device;

int main() {

    // Initializing OpenCL.
    setContext(&device, &context, TRUE);

    // Run tests
    if (!run_all_tests(device, context, FALSE)) {
        return 1;
    }

    char *iterate_particle_files[] = {PROJECT_DIR "/util/kernelUtils.cl",
                                      PROJECT_DIR "/kernels/get_gravity/no_gravity.cl",
                                      PROJECT_DIR "/kernels/get_vel_fluid/tgv.cl",
                                      PROJECT_DIR "/kernels/iterate_particle.cl"};
    cl_kernel iterate_particle = getKernel(device, context, iterate_particle_files, 4, "iterate_particle", TRUE);

    hparticles = malloc(sizeof(particle) * NUMPART);

    hparticles[0].diameter = particle_diameter;
    hparticles[0].effect_diameter = 0;
    hparticles[0].fluid_viscosity = fluid_viscosity;
    hparticles[0].density = density;
    hparticles[0].id = 0;
    hparticles[0].pos = (cl_float3) {0, 0, 0};
    hparticles[0].vel = (cl_float3) {initial_vel_x, 0, 0};
    hparticles[0].forces = (cl_float3) {0, 0, 0};

    float tau = get_tau(&(hparticles[0]));
    sim_length = 10 * tau;

    domain_length = 0.5;
    printf("Mass = %f\n", get_particle_mass(&(hparticles[0])));
    printf("Tau = %f\n", tau);

    char dir[] = PROJECT_DIR "/verification/gravity_drag/data/";
    //for (int i = 8; i <= 64; i *= 2) {
    timestep = tau / 2;
    log_step = timestep;

    //sprintf(prefix, "drag");

    hparticles[0].pos = (cl_float3) {0, 0, 0};
    hparticles[0].vel = (cl_float3) {0, 0, 0};

    runSim(hparticles, NUMPART, iterate_particle, particle_diameter, FALSE, domain_length,
           prefix, dir, sim_length, timestep, VERBOSE, LOG_DATA, TRUE, log_step, device, context);
    //}
}