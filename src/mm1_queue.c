#include "distributions.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


double* lindley_wait_times(int n, double* T, double* S) {
    // Use Lindley's recurrence to determine wait times
    double* W = (double*)malloc(sizeof(double)*(n+1));
    *W = 0;

    for(int i=0; i<n; i++) {
        if(S[i]-T[i]+W[i] > 0.00000000001)
            W[i+1] = S[i]-T[i]+W[i];
        else
            W[i+1] = 0.0;
    }
    
    return W;
}

void print_table(int n, double* T, double* S, double* W) {
    // Print table
    printf("i\tT[i]\tS[i]\tW[i]\n");
    printf("-------------------------------\n");
    for(int i=1; i<n+1; i++) {
        printf("%d\t%0.4f\t%0.4f\t%0.4f\n", i, T[i], S[i], W[i]);
    }
}


int main(int argc, char** argv) {

    // Seed the pRNG
    srand(time(NULL));   

    // Parameters
    int n = 2000;
    double TT = 500.0;
    double lambda = 3.0;
    double mu = 4.0;
    double rho = lambda/mu;
    double rho_hat = 0.0;

    // Generate interarrival times
    double* T = (double*)malloc(sizeof(double)*(n+1));
    *T = 0;
   
    for(int i=1; i<n+1; i++) {
        T[i] = expo(lambda);
    }

    // Generate service times
    double* S = (double*)malloc(sizeof(double)*(n+1));
    *S = 0;
    
    for(int i=1; i<n+1; i++) {
        S[i] = expo(mu);
    }
    
    // Compute wait times using Lindley's recursion
    double* W = lindley_wait_times(n,T,S);


    print_table(200,T,S,W);   

    double avg_wait_time = 0.0;
    double avg_interarrival_time = 0.0;
    double avg_service_time = 0.0;
    int num_wait_times = 0;

    for(int i=1;i<n+1; i++) {
        avg_wait_time += W[i];
        avg_interarrival_time += T[i];
        avg_service_time += S[i];
        num_wait_times += W[i]>0.000000001 ? 1 : 0;
    }
    
    avg_wait_time /= (double)n;
    avg_interarrival_time /= (double)n;
    avg_service_time /= (double)n;
    

    printf("\nAverage i.a time:\t%0.4f\n", avg_interarrival_time);
    printf("Average service time:\t%0.4f\n", avg_service_time);

    printf("Average wait time:\t%0.4f\n", avg_wait_time);

    printf("Theoretical wait time:\t%0.4f\n", rho*rho/(lambda*(1-rho)));

    return 0;
}


