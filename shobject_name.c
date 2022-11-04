/*
 * Replace the following string of 0s with your student number
 * c0034805
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "sim_config.h"
#include "shobject_name.h"

const char* SHOBJ_NAME_FORMAT = "/csc2035.%.9s.%.12s";

/* 
 * TODO you must implement this function.
 *
 * Hints:
 * - from its specification in shobject_name.h this function may seem 
 *      complicated, in fact almost everything will be covered in C 
 *      programming module materials
 * - there is a library function for getting the current user from the 
 *      environment (use "anon" if the function returns NULL)
 */
char* shobject_name(char* name_buf, const char* label) {
    char* current_user = getenv("USER");
    char* label_copy = (char*) malloc(sizeof(char) * MAX_NAME_SIZE);

    if(!current_user){
        current_user = "anon";
    }

    if(!label || !label[0]){
        label_copy = "none";
    }
    else{
        strncpy(label_copy, label, MAX_NAME_SIZE);
        label_copy[MAX_NAME_SIZE - 1] = '\0';
    }

    if(name_buf){
        snprintf(name_buf, MAX_NAME_SIZE, SHOBJ_NAME_FORMAT, current_user, label_copy);
        return name_buf;
    }

    char* new_buf = (char*) malloc(sizeof(char) * MAX_NAME_SIZE);

    snprintf(new_buf, MAX_NAME_SIZE, SHOBJ_NAME_FORMAT, current_user, label_copy);
    return new_buf;     
}
