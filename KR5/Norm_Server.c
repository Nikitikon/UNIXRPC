//
//  Norm_Server.c
//  KR5
//
//  Created by Nikita-Mac on 16.05.17.
//  Copyright © 2017 Nikita-Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include <math.h>
#include <time.h>
#include "RNORM.h"


double * mypi_1_svc(void *p, struct svc_req * cl){
    static double result = 0;
    double const Const = 2 * sqrt(3);
    
    for (int i = 0; i < 10000; i++) {
        double temp = pow(-1, i) / pow(3, i);
        temp /= 2 * i + 1;
        result += temp * Const;
    }
    return &result;
}

double * myexp_1_svc(int *p, struct svc_req *cl){
    int x = *p;
    double parameter = -(double)(x * x)/2;
    static double result = 1;
    int n = 1;
    
    for (int i = 1; i < 20; i++) {
        n *= i;
        result += pow(parameter, i) / n;
    }
    
    return &result;
}



