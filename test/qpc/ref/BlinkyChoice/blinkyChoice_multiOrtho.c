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


 
#include <stdio.h>
#include <string.h>
#include <log_event.h>
#include <assert.h>
#include <blinkyChoice_multiOrtho.h>
#include <blinkyChoice_multiOrtho_impl.h>




// Orthogonal regions initialized here
unnamedState0_region1 unnamedState0_region1_inst;
unnamedState0_region2 unnamedState0_region2_inst;
unnamedState1_region3 unnamedState1_region3_inst;
unnamedState1_region4 unnamedState1_region4_inst;



/**
 * blinkyChoice_multiOrtho Constructor
 */
blinkyChoice_multiOrtho *blinkyChoice_multiOrtho_constructor (blinkyChoice_multiOrtho *me, const char *objNameNew, blinkyChoice_multiOrtho_impl *implObj, QActive *active) {
    QActive_ctor((QActive *)me, (QStateHandler )&blinkyChoice_multiOrtho_initial);
    strncpy(me->objName, objNameNew, 128);
    strncat(me->objName, ":blinkyChoice_multiOrtho", 128-strlen(me->objName));
    me->impl = implObj;
    if (0 == active) {  // self IS the active object
        me->active = (QActive *)me;
    } else {  // set containing machine as active object
        me->active = active;
    }
    blinkyChoice_multiOrtho_impl_set_qactive(me->impl, me->active);  // give impl access to parent QActive

    // Orthogonal regions initialized here
    me->region1 = &unnamedState0_region1_inst;
    (void)unnamedState0_region1_constructor(me->region1, me->impl, me->active, me);
    me->region2 = &unnamedState0_region2_inst;
    (void)unnamedState0_region2_constructor(me->region2, me->impl, me->active, me);
    me->region3 = &unnamedState1_region3_inst;
    (void)unnamedState1_region3_constructor(me->region3, me->impl, me->active, me);
    me->region4 = &unnamedState1_region4_inst;
    (void)unnamedState1_region4_constructor(me->region4, me->impl, me->active, me);


    // State is initially at TOP
    me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;

    return me;
}

blinkyChoice_multiOrtho_impl *blinkyChoice_multiOrtho_get_impl (blinkyChoice_multiOrtho *me) {
    return me->impl;
}

blinkyChoice_multiOrtho_state blinkyChoice_multiOrtho_get_current_state (blinkyChoice_multiOrtho *me) {
    return me->myState;
}

/**
 * initial state definition
 */
QState blinkyChoice_multiOrtho_initial (blinkyChoice_multiOrtho *me, QEvt const *e) {
    // Subscribe to all the signals to which this state machine needs to respond.
	if (me->active == (QActive *)me) {
		QActive_subscribe(me->active, BLINKYCHOICE_TURN_OFF_SIG);
		QActive_subscribe(me->active, BLINKYCHOICE_TURN_ON_SIG);
		QActive_subscribe(me->active, BLINKYCHOICE_WIF_HEY_SIG);
		QActive_subscribe(me->active, _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_COMPLETE_);
		QActive_subscribe(me->active, _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_COMPLETE_);
	}

    return Q_TRAN(&blinkyChoice_multiOrtho_hryoo);
}

/**
 * hryoo state definition
 */
QState blinkyChoice_multiOrtho_hryoo (blinkyChoice_multiOrtho *me, QEvt const *e) {
    switch (e->sig) {
        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_HRYOO;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_WIF_HEY_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0);

        case BLINKYCHOICE_TURN_ON_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1);


    }
    return Q_SUPER(&QHsm_top);
}

/**
 * unnamedState0 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState0 (blinkyChoice_multiOrtho *me, QEvt const *e) {
    switch (e->sig) {
        case BLINKYCHOICE_TURN_OFF_SIG:
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region1), e);
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region2), e);

            return Q_HANDLED();

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0;
            QF_ACTIVE_INIT_((QHsm *)(me->region1), e);
            QF_ACTIVE_INIT_((QHsm *)(me->region2), e);

            return Q_HANDLED();

        case Q_EXIT_SIG:
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region1),
                                        &(me->BLINKYCHOICE_MULTIORTHO_BAIL_EVENT_));
            unnamedState0_region1_reinit(me->region1);
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region2),
                                        &(me->BLINKYCHOICE_MULTIORTHO_BAIL_EVENT_));
            unnamedState0_region2_reinit(me->region2);

            return Q_HANDLED();


    }
    return Q_SUPER(&QHsm_top);
}

// ############ Utility method definitions for orthogonal region: unnamedState0_region1 ############

/** 
 * Orthogonal-region constructor for unnamedState0_region1
 */
unnamedState0_region1 *unnamedState0_region1_constructor (unnamedState0_region1 *me, const char *objNameNew, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent) {
    QHsm_ctor((QHsm *)me, (QStateHandler )unnamedState0_region1_initial);
    strncpy(me->objName, objNameNew, 128);
    me->objName[128-1] = '\0';  // null-terminate string
    me->impl = implObj;
    me->active = active;
    me->parent = parent;

    // State is initially at TOP
    me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;

    return me;
}

blinkyChoice_multiOrtho_state unnamedState0_region1_get_current_state (unnamedState0_region1 *me) {
    return me->myState;
}

void unnamedState0_region1_reinit (unnamedState0_region1 *me) {
    ((QHsm *)me)->state = (QStateHandler ) &unnamedState0_region1_initial;
}

// ############ State handler methods definitions for orthogonal region: unnamedState0_region1 ############

/**
 * Initial transition of the state machine (equivalent to initial pseudostate node)
 * This routine handles initial events of the state-machine.
 */
QState blinkyChoice_multiOrtho_unnamedState0_region1_initial (unnamedState0_region1 *me, QEvt const *e) {
    return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region1_state1);
}

QState blinkyChoice_multiOrtho_unnamedState0_region1_final (unnamedState0_region1 *me, QEvt const *e) {
    switch (e->sig) {
    case Q_ENTRY_SIG:
        me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;
        return Q_HANDLED();
    case Q_EXIT_SIG:
        return Q_HANDLED();
    case Q_BAIL_SIG:  // prevents dropped event if submachine already terminated
        return Q_HANDLED();
    }
    return Q_SUPER(&QHsm_top);
}

/**
 * state1 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState0_region1_state1 (unnamedState0_region1 *me, QEvt const *e) {
    switch (e->sig) {
        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region1_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_REGION1_STATE1;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_TURN_OFF_SIG:

            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.super.sig = _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_COMPLETE_;
            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.substate = NULL;  // Comodo functionality not implemented
            QF_publish_(&(me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.base_evt));
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region1_finalState0);


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState0);
}

/**
 * finalState0 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState0_region1_finalState0 (unnamedState0_region1 *me, QEvt const *e) {
    switch (e->sig) {
        case _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_COMPLETE_:
            return Q_HANDLED();

        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region1_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_REGION1_FINALSTATE0;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState0);
}

// ############ Utility method definitions for orthogonal region: unnamedState0_region2 ############

/** 
 * Orthogonal-region constructor for unnamedState0_region2
 */
unnamedState0_region2 *unnamedState0_region2_constructor (unnamedState0_region2 *me, const char *objNameNew, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent) {
    QHsm_ctor((QHsm *)me, (QStateHandler )unnamedState0_region2_initial);
    strncpy(me->objName, objNameNew, 128);
    me->objName[128-1] = '\0';  // null-terminate string
    me->impl = implObj;
    me->active = active;
    me->parent = parent;

    // State is initially at TOP
    me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;

    return me;
}

blinkyChoice_multiOrtho_state unnamedState0_region2_get_current_state (unnamedState0_region2 *me) {
    return me->myState;
}

void unnamedState0_region2_reinit (unnamedState0_region2 *me) {
    ((QHsm *)me)->state = (QStateHandler ) &unnamedState0_region2_initial;
}

// ############ State handler methods definitions for orthogonal region: unnamedState0_region2 ############

/**
 * Initial transition of the state machine (equivalent to initial pseudostate node)
 * This routine handles initial events of the state-machine.
 */
QState blinkyChoice_multiOrtho_unnamedState0_region2_initial (unnamedState0_region2 *me, QEvt const *e) {
    return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region2_state2);
}

QState blinkyChoice_multiOrtho_unnamedState0_region2_final (unnamedState0_region2 *me, QEvt const *e) {
    switch (e->sig) {
    case Q_ENTRY_SIG:
        me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;
        return Q_HANDLED();
    case Q_EXIT_SIG:
        return Q_HANDLED();
    case Q_BAIL_SIG:  // prevents dropped event if submachine already terminated
        return Q_HANDLED();
    }
    return Q_SUPER(&QHsm_top);
}

/**
 * state2 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState0_region2_state2 (unnamedState0_region2 *me, QEvt const *e) {
    switch (e->sig) {
        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region2_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_REGION2_STATE2;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_TURN_OFF_SIG:

            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.super.sig = _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_COMPLETE_;
            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.substate = NULL;  // Comodo functionality not implemented
            QF_publish_(&(me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.base_evt));
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region2_finalState1);


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState0);
}

/**
 * finalState1 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState0_region2_finalState1 (unnamedState0_region2 *me, QEvt const *e) {
    switch (e->sig) {
        case _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_COMPLETE_:
            return Q_HANDLED();

        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState0_region2_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE0_REGION2_FINALSTATE1;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState0);
}

/**
 * unnamedState1 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState1 (blinkyChoice_multiOrtho *me, QEvt const *e) {
    switch (e->sig) {
        case BLINKYCHOICE_TURN_OFF_SIG:
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region3), e);
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region4), e);

            return Q_HANDLED();

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1;
            QF_ACTIVE_INIT_((QHsm *)(me->region3), e);
            QF_ACTIVE_INIT_((QHsm *)(me->region4), e);

            return Q_HANDLED();

        case Q_EXIT_SIG:
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region3),
                                        &(me->BLINKYCHOICE_MULTIORTHO_BAIL_EVENT_));
            unnamedState1_region3_reinit(me->region3);
            QF_ACTIVE_DISPATCH_((QHsm *)(me->region4),
                                        &(me->BLINKYCHOICE_MULTIORTHO_BAIL_EVENT_));
            unnamedState1_region4_reinit(me->region4);

            return Q_HANDLED();


    }
    return Q_SUPER(&QHsm_top);
}

// ############ Utility method definitions for orthogonal region: unnamedState1_region3 ############

/** 
 * Orthogonal-region constructor for unnamedState1_region3
 */
unnamedState1_region3 *unnamedState1_region3_constructor (unnamedState1_region3 *me, const char *objNameNew, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent) {
    QHsm_ctor((QHsm *)me, (QStateHandler )unnamedState1_region3_initial);
    strncpy(me->objName, objNameNew, 128);
    me->objName[128-1] = '\0';  // null-terminate string
    me->impl = implObj;
    me->active = active;
    me->parent = parent;

    // State is initially at TOP
    me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;

    return me;
}

blinkyChoice_multiOrtho_state unnamedState1_region3_get_current_state (unnamedState1_region3 *me) {
    return me->myState;
}

void unnamedState1_region3_reinit (unnamedState1_region3 *me) {
    ((QHsm *)me)->state = (QStateHandler ) &unnamedState1_region3_initial;
}

// ############ State handler methods definitions for orthogonal region: unnamedState1_region3 ############

/**
 * Initial transition of the state machine (equivalent to initial pseudostate node)
 * This routine handles initial events of the state-machine.
 */
QState blinkyChoice_multiOrtho_unnamedState1_region3_initial (unnamedState1_region3 *me, QEvt const *e) {
    return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region3_unnamedState2);
}

QState blinkyChoice_multiOrtho_unnamedState1_region3_final (unnamedState1_region3 *me, QEvt const *e) {
    switch (e->sig) {
    case Q_ENTRY_SIG:
        me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;
        return Q_HANDLED();
    case Q_EXIT_SIG:
        return Q_HANDLED();
    case Q_BAIL_SIG:  // prevents dropped event if submachine already terminated
        return Q_HANDLED();
    }
    return Q_SUPER(&QHsm_top);
}

/**
 * unnamedState2 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState1_region3_unnamedState2 (unnamedState1_region3 *me, QEvt const *e) {
    switch (e->sig) {
        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region3_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_REGION3_UNNAMEDSTATE2;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_TURN_OFF_SIG:

            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.super.sig = _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_COMPLETE_;
            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.substate = NULL;  // Comodo functionality not implemented
            QF_publish_(&(me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.base_evt));
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region3_finalState2);


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState1);
}

/**
 * finalState2 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState1_region3_finalState2 (unnamedState1_region3 *me, QEvt const *e) {
    switch (e->sig) {
        case _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_COMPLETE_:
            return Q_HANDLED();

        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region3_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_REGION3_FINALSTATE2;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState1);
}

// ############ Utility method definitions for orthogonal region: unnamedState1_region4 ############

/** 
 * Orthogonal-region constructor for unnamedState1_region4
 */
unnamedState1_region4 *unnamedState1_region4_constructor (unnamedState1_region4 *me, const char *objNameNew, blinkyChoice_multiOrtho_impl *implObj, QActive *active, blinkyChoice_multiOrtho *parent) {
    QHsm_ctor((QHsm *)me, (QStateHandler )unnamedState1_region4_initial);
    strncpy(me->objName, objNameNew, 128);
    me->objName[128-1] = '\0';  // null-terminate string
    me->impl = implObj;
    me->active = active;
    me->parent = parent;

    // State is initially at TOP
    me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;

    return me;
}

blinkyChoice_multiOrtho_state unnamedState1_region4_get_current_state (unnamedState1_region4 *me) {
    return me->myState;
}

void unnamedState1_region4_reinit (unnamedState1_region4 *me) {
    ((QHsm *)me)->state = (QStateHandler ) &unnamedState1_region4_initial;
}

// ############ State handler methods definitions for orthogonal region: unnamedState1_region4 ############

/**
 * Initial transition of the state machine (equivalent to initial pseudostate node)
 * This routine handles initial events of the state-machine.
 */
QState blinkyChoice_multiOrtho_unnamedState1_region4_initial (unnamedState1_region4 *me, QEvt const *e) {
    return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region4_unnamedState3);
}

QState blinkyChoice_multiOrtho_unnamedState1_region4_final (unnamedState1_region4 *me, QEvt const *e) {
    switch (e->sig) {
    case Q_ENTRY_SIG:
        me->myState = BLINKYCHOICE_MULTIORTHO__TOP__;
        return Q_HANDLED();
    case Q_EXIT_SIG:
        return Q_HANDLED();
    case Q_BAIL_SIG:  // prevents dropped event if submachine already terminated
        return Q_HANDLED();
    }
    return Q_SUPER(&QHsm_top);
}

/**
 * unnamedState3 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState1_region4_unnamedState3 (unnamedState1_region4 *me, QEvt const *e) {
    switch (e->sig) {
        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region4_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_REGION4_UNNAMEDSTATE3;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_TURN_OFF_SIG:

            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.super.sig = _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_COMPLETE_;
            me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.completion_evt.substate = NULL;  // Comodo functionality not implemented
            QF_publish_(&(me->BLINKYCHOICE_MULTIORTHO_COMPLETION_EVENT_.base_evt));
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region4_finalState3);


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState1);
}

/**
 * finalState3 state definition
 */
QState blinkyChoice_multiOrtho_unnamedState1_region4_finalState3 (unnamedState1_region4 *me, QEvt const *e) {
    switch (e->sig) {
        case _SIG_BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_COMPLETE_:
            return Q_HANDLED();

        case Q_BAIL_SIG:
            return Q_TRAN(&blinkyChoice_multiOrtho_unnamedState1_region4_final);

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MULTIORTHO_UNNAMEDSTATE1_REGION4_FINALSTATE3;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();


    }
    return Q_SUPER(&blinkyChoice_multiOrtho_unnamedState1);
}
