/* 
 * This code was generated by Comodo (https://github.com/Open-MBEE/Comodo) 
 * using the QPC-C Target Platform
 *
 * - Generated Class (Comodo Module):
 *      blinkyChoice
 *
 * - Generated State Machine (Comodo Component):
 *      multiOrtho
 * 
 *
 * ############### Requirements ###############
 *  Implements: 
 * - https://<traceability-service-hostname>/724776 
 * - https://<traceability-service-hostname>/724777 
 *
 * ############################################
 *
 */


 

#ifndef BLINKYCHOICE_MULTIORTHO_H_
#define BLINKYCHOICE_MULTIORTHO_H_

#include <stdbool.h>
#include <qf_port.h>
#include <qassert.h>
#include <blinkyChoice_statechart_signals.h>
#include <blinkyChoice_multiOrtho_states.h>
#include <blinkyChoice_multiOrtho_impl.h>


/* Forward declarations for orthogonal-region struct field of containing SM */
typedef struct unnamedState0_region1 unnamedState0_region1;
typedef struct unnamedState0_region2 unnamedState0_region2;
typedef struct unnamedState1_region3 unnamedState1_region3;
typedef struct unnamedState1_region4 unnamedState1_region4;

/**
 * Declare the state machine struct, encapsulating the extended state variables.
 * It tracks any timers, owned orthogonal regions, history states, substates.
 */
typedef struct blinkyChoice_multiOrtho {
    QActive super;  // C-style inheritance
    QActive *active;  // containing machine if this is a submachine instance
    char objName[128];
    blinkyChoice_multiOrtho_impl *impl;
    enum blinkyChoice_multiOrtho_state myState;

    /* Orthogonal region instance pointers */
    unnamedState0_region1 *region1;
    unnamedState0_region2 *region2;
    unnamedState1_region3 *region3;
    unnamedState1_region4 *region4;

    /* Completion event for exiting from composite/orthogonal/submachine state */
    QCompletionEvt BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_;

    /* Bail event to terminate orthogonal/submachine substate */
    QEvt BLINKYCHOICE_MULTIORTHO_BAIL_EVENT_;

} blinkyChoice_multiOrtho;


/** 
 * blinkyChoice_multiOrtho Constructor
 *
 * This State machine constructor is responsible for initializing
 * the object, allocating and initializing any orthogonal regions, 
 * and initializing the timers.
 */
blinkyChoice_multiOrtho *blinkyChoice_multiOrtho_constructor (blinkyChoice_multiOrtho *me, const char *objNameNew, blinkyChoice_multiOrtho_impl *implObj, QActive *active);

/**
  * Returns the instance of the Implementation class for this QActive.
  */
blinkyChoice_multiOrtho_impl *blinkyChoice_multiOrtho_get_impl (blinkyChoice_multiOrtho *me);

/**
 * Returns the unique enum representing the current state of this machine.
 */
blinkyChoice_multiOrtho_state blinkyChoice_multiOrtho_get_current_state (blinkyChoice_multiOrtho *me);

/**
 * Method to initialize state machine (equivalent to initial pseudostate)
 */
QState blinkyChoice_multiOrtho_initial (blinkyChoice_multiOrtho *me, QEvt const *e);

/**
 * State methods
 */
QState blinkyChoice_multiOrtho_hryoo(blinkyChoice_multiOrtho *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState0(blinkyChoice_multiOrtho *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState0_region1_state1(unnamedState0_region1 *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState0_region1_finalState0(unnamedState0_region1 *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState0_region2_state2(unnamedState0_region2 *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState0_region2_finalState1(unnamedState0_region2 *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState1(blinkyChoice_multiOrtho *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState1_region3_unnamedState2(unnamedState1_region3 *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState1_region3_finalState2(unnamedState1_region3 *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState1_region4_unnamedState3(unnamedState1_region4 *me, QEvt const *e); 
QState blinkyChoice_multiOrtho_unnamedState1_region4_finalState3(unnamedState1_region4 *me, QEvt const *e); 



/**
 * Declare the state machine struct, encapsulating the extended state variables.
 * It tracks any timers, owned orthogonal regions, history states, substates.
 */
struct unnamedState0_region1 {
    QHsm super;  // C-style inheritance
    QActive *active;  // containing machine if this is a submachine instance
    blinkyChoice_multiOrtho *parent;  // parent active machine for access to timers
    blinkyChoice_multiOrtho_impl *impl;
    enum blinkyChoice_multiOrtho_state myState;
};  

/** 
 * Orthogonal-region constructor for unnamedState0_region1
 *
 * This State machine constructor is responsible for initializing
 * the object, allocating and initializing any orthogonal regions, 
 * and initializing the timers.
 */
unnamedState0_region1 *unnamedState0_region1_constructor (unnamedState0_region1 *me, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent);

/**
 * Returns the unique enum representing current state within this region.
 */
orthogonal_state unnamedState0_region1_get_current_state (unnamedState0_region1 *me);

/**
 * Re-initializes a region, invoked upon exit from region.
 */
void unnamedState0_region1_reinit (unnamedState0_region1 *me);

/**
 * Method to initialize region to initial pseudostates
 */
QState blinkyChoice_multiOrtho_unnamedState0_region1_initial (unnamedState0_region1 *me, QEvt const *e);

/**
 * Method representing state machine final state
 * This will get autogenerated even if the rergion doesn't have a final node.
 */
QState blinkyChoice_multiOrtho_unnamedState0_region1_final (unnamedState0_region1 *me, QEvt const *e); 

/**
 * Declare the state machine struct, encapsulating the extended state variables.
 * It tracks any timers, owned orthogonal regions, history states, substates.
 */
struct unnamedState0_region2 {
    QHsm super;  // C-style inheritance
    QActive *active;  // containing machine if this is a submachine instance
    blinkyChoice_multiOrtho *parent;  // parent active machine for access to timers
    blinkyChoice_multiOrtho_impl *impl;
    enum blinkyChoice_multiOrtho_state myState;
};  

/** 
 * Orthogonal-region constructor for unnamedState0_region2
 *
 * This State machine constructor is responsible for initializing
 * the object, allocating and initializing any orthogonal regions, 
 * and initializing the timers.
 */
unnamedState0_region2 *unnamedState0_region2_constructor (unnamedState0_region2 *me, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent);

/**
 * Returns the unique enum representing current state within this region.
 */
orthogonal_state unnamedState0_region2_get_current_state (unnamedState0_region2 *me);

/**
 * Re-initializes a region, invoked upon exit from region.
 */
void unnamedState0_region2_reinit (unnamedState0_region2 *me);

/**
 * Method to initialize region to initial pseudostates
 */
QState blinkyChoice_multiOrtho_unnamedState0_region2_initial (unnamedState0_region2 *me, QEvt const *e);

/**
 * Method representing state machine final state
 * This will get autogenerated even if the rergion doesn't have a final node.
 */
QState blinkyChoice_multiOrtho_unnamedState0_region2_final (unnamedState0_region2 *me, QEvt const *e); 

/**
 * Declare the state machine struct, encapsulating the extended state variables.
 * It tracks any timers, owned orthogonal regions, history states, substates.
 */
struct unnamedState1_region3 {
    QHsm super;  // C-style inheritance
    QActive *active;  // containing machine if this is a submachine instance
    blinkyChoice_multiOrtho *parent;  // parent active machine for access to timers
    blinkyChoice_multiOrtho_impl *impl;
    enum blinkyChoice_multiOrtho_state myState;
};  

/** 
 * Orthogonal-region constructor for unnamedState1_region3
 *
 * This State machine constructor is responsible for initializing
 * the object, allocating and initializing any orthogonal regions, 
 * and initializing the timers.
 */
unnamedState1_region3 *unnamedState1_region3_constructor (unnamedState1_region3 *me, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent);

/**
 * Returns the unique enum representing current state within this region.
 */
orthogonal_state unnamedState1_region3_get_current_state (unnamedState1_region3 *me);

/**
 * Re-initializes a region, invoked upon exit from region.
 */
void unnamedState1_region3_reinit (unnamedState1_region3 *me);

/**
 * Method to initialize region to initial pseudostates
 */
QState blinkyChoice_multiOrtho_unnamedState1_region3_initial (unnamedState1_region3 *me, QEvt const *e);

/**
 * Method representing state machine final state
 * This will get autogenerated even if the rergion doesn't have a final node.
 */
QState blinkyChoice_multiOrtho_unnamedState1_region3_final (unnamedState1_region3 *me, QEvt const *e); 

/**
 * Declare the state machine struct, encapsulating the extended state variables.
 * It tracks any timers, owned orthogonal regions, history states, substates.
 */
struct unnamedState1_region4 {
    QHsm super;  // C-style inheritance
    QActive *active;  // containing machine if this is a submachine instance
    blinkyChoice_multiOrtho *parent;  // parent active machine for access to timers
    blinkyChoice_multiOrtho_impl *impl;
    enum blinkyChoice_multiOrtho_state myState;
};  

/** 
 * Orthogonal-region constructor for unnamedState1_region4
 *
 * This State machine constructor is responsible for initializing
 * the object, allocating and initializing any orthogonal regions, 
 * and initializing the timers.
 */
unnamedState1_region4 *unnamedState1_region4_constructor (unnamedState1_region4 *me, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent);

/**
 * Returns the unique enum representing current state within this region.
 */
orthogonal_state unnamedState1_region4_get_current_state (unnamedState1_region4 *me);

/**
 * Re-initializes a region, invoked upon exit from region.
 */
void unnamedState1_region4_reinit (unnamedState1_region4 *me);

/**
 * Method to initialize region to initial pseudostates
 */
QState blinkyChoice_multiOrtho_unnamedState1_region4_initial (unnamedState1_region4 *me, QEvt const *e);

/**
 * Method representing state machine final state
 * This will get autogenerated even if the rergion doesn't have a final node.
 */
QState blinkyChoice_multiOrtho_unnamedState1_region4_final (unnamedState1_region4 *me, QEvt const *e); 





#endif /* BLINKYCHOICE_MULTIORTHO_H_ */
