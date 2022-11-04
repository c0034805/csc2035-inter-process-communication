/******** DO NOT EDIT THIS FILE ********/
/* 
 * test_jobqueue_common.h - structures and function declarations for
 * common unit tests of jobqueue, ipc_jobqueue and sem_ipc_jobqueue functions.
 */  
#ifndef _TEST_JOBQUEUE_COMMON_H
#define _TEST_JOBQUEUE_COMMON_H
#define MUNIT_ENABLE_ASSERT_ALIASES
#include <stdbool.h>
#include "munit/munit.h"
#include "../sim_config.h"
#include "../job.h"
#include "../jobqueue.h"

typedef struct test_jq {
    /* queue to test */
    void* q;
    /* pointers to queue functions to test */
    size_t (*capacity)(void*);
    bool (*is_full)(void*);
    bool (*is_empty)(void*);
    void (*enqueue)(void*, job_t*);
    job_t* (*dequeue)(void*, job_t*);
    job_t* (*peekhead)(void*, job_t*);
    job_t* (*peektail)(void*, job_t*);
    /* additional fields for verification of queue's internal state in tests */
    int* head;
    int* tail;
    int* buf_size;
    job_t* jobs;
} test_jq_t;

// utility functions
void set_job(job_t* j, pid_t pid, unsigned int id, const char* label);
bool jobs_initialised(job_t* jobs, size_t buf_size);
void assert_queue_initialised(jobqueue_t* q);
bool equal_jobs(job_t* j1, job_t* j2);
// tests
MunitResult test_jq_capacity(test_jq_t* test_jq);
MunitResult test_jq_capacity_null(test_jq_t* test_jq);

MunitResult test_jq_dequeue_fullq(test_jq_t* test_jq);
MunitResult test_jq_dequeue_inout(test_jq_t* test_jq);
MunitResult test_jq_dequeue_emptyq(test_jq_t* test_jq);
MunitResult test_jq_dequeue_heap(test_jq_t* test_jq);
MunitResult test_jq_dequeue_null(test_jq_t* test_jq);

MunitResult test_jq_enqueue_tofull(test_jq_t* test_jq);
MunitResult test_jq_enqueue_inout(test_jq_t* test_jq);
MunitResult test_jq_enqueue_fullq(test_jq_t* test_jq);
MunitResult test_jq_enqueue_null(test_jq_t* test_jq);

MunitResult test_jq_is_empty(test_jq_t* test_jq);
MunitResult test_jq_is_empty_notempty(test_jq_t* test_jq);
MunitResult test_jq_is_empty_null(test_jq_t* test_jq);

MunitResult test_jq_is_full_empty(test_jq_t* test_jq);
MunitResult test_jq_is_full_filling(test_jq_t* test_jq);
MunitResult test_jq_is_full_null(test_jq_t* test_jq);

MunitResult test_jq_peekhead_empty(test_jq_t* test_jq);
MunitResult test_jq_peekhead_full(test_jq_t* test_jq);
MunitResult test_jq_peekhead_heap(test_jq_t* test_jq);
MunitResult test_jq_peekhead_null(test_jq_t* test_jq);

MunitResult test_jq_peektail_empty(test_jq_t* test_jq);
MunitResult test_jq_peektail_full(test_jq_t* test_jq);
MunitResult test_jq_peektail_heap(test_jq_t* test_jq);
MunitResult test_jq_peektail_wrap(test_jq_t* test_jq);
MunitResult test_jq_peektail_null(test_jq_t* test_jq);
#endif