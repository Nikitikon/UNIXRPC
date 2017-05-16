//
//  Norm_Client.c
//  KR5
//
//  Created by Nikita-Mac on 16.05.17.
//  Copyright © 2017 Nikita-Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <rpc/rpc.h>
#include <math.h>
#include "RNORM.h"
#define RMACHINE "localhost"

CLIENT *handle;

double Pi(){
    return *mypi_1(NULL, handle);
}

double Exp(int x){
    return *myexp_1(&x, handle);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    handle = clnt_create(RMACHINE, RNORM_PROG, RNORM_VARS, "tcp");
    if (handle == NULL) {
        perror("create");
        exit(0);
    }
    
    double pi = sqrt(2 * Pi());
    double e = Exp(1);
    printf("%f", e / pi);
    return 0;
}
