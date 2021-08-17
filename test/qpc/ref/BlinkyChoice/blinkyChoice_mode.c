/* 
 * This code was generated by Comodo (https://github.com/Open-MBEE/Comodo) 
 * using the QPC-C Target Platform
 *
 * - Generated Class (Comodo Module):
 *      blinkyChoice
 *
 * - Generated State Machine (Comodo Component):
 *      mode
 * 
 *
 * ############### Requirements ###############
 *  Implements: 
 * - https://cae-jama.jpl.nasa.gov/rest/latest/items/724776 
 * - https://cae-jama.jpl.nasa.gov/rest/latest/items/724777 
 *
 * ############################################
 *
 */


 
#include <stdio.h>
#include <string.h>
#include <log_event.h>
#include <assert.h>
#include <blinkyChoice_mode.h>
#include <blinkyChoice_mode_impl.h>





/**
 * blinkyChoice_mode Constructor
 */
blinkyChoice_mode *blinkyChoice_mode_constructor (blinkyChoice_mode *me, const char *objNameNew, blinkyChoice_mode_impl *implObj, QActive *active) {
    QActive_ctor((QActive *)me, (QStateHandler )&blinkyChoice_mode_initial);
    strncpy(me->objName, objNameNew, 128);
    strncat(me->objName, ":blinkyChoice_mode", 128-strlen(me->objName));
    me->impl = implObj;
    if (0 == active) {  // self IS the active object
        me->active = (QActive *)me;
    } else {  // set containing machine as active object
        me->active = active;
    }
    blinkyChoice_mode_impl_set_qactive(me->impl, me->active);  // give impl access to parent QActive

    // State is initially at TOP
    me->myState = BLINKYCHOICE_MODE__TOP__;

    return me;
}

blinkyChoice_mode_impl *blinkyChoice_mode_get_impl (blinkyChoice_mode *me) {
    return me->impl;
}

blinkyChoice_mode_state blinkyChoice_mode_get_current_state (blinkyChoice_mode *me) {
    return me->myState;
}

/**
 * initial state definition
 */
QState blinkyChoice_mode_initial (blinkyChoice_mode *me, QEvt const *e) {
    // Subscribe to all the signals to which this state machine needs to respond.
	if (me->active == (QActive *)me) {
		QActive_subscribe(me->active, BLINKYCHOICE_TURN_OFF_SIG);
		QActive_subscribe(me->active, BLINKYCHOICE_TURN_ON_SIG);
		QActive_subscribe(me->active, BLINKYCHOICE_WIF_HEY_SIG);
		QActive_subscribe(me->active, _SIG_BLINKYCHOICE_MODE_COMPLETE_);
	}

    return Q_TRAN(&blinkyChoice_mode_unnamedState0);
}

/**
 * finalState0 state definition
 */
QState blinkyChoice_mode_finalState0 (blinkyChoice_mode *me, QEvt const *e) {
    switch (e->sig) {
        case _SIG_BLINKYCHOICE_MODE_COMPLETE_:
            return Q_HANDLED();

        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MODE_FINALSTATE0;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();


    }
    return Q_SUPER(&QHsm_top);
}

/**
 * off state definition
 */
QState blinkyChoice_mode_off (blinkyChoice_mode *me, QEvt const *e) {
    switch (e->sig) {
        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MODE_OFF;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_TURN_ON_SIG:
            return Q_TRAN(&blinkyChoice_mode_on);

        case BLINKYCHOICE_TURN_OFF_SIG:
            if (blinkyChoice_mode_impl_hey(me->impl)){
                return Q_TRAN(&blinkyChoice_mode_finalState0);
            }

            me->BLINKYCHOICE_MODE_COMPLETION_EVENT_.completion_evt.super.sig = _SIG_BLINKYCHOICE_MODE_COMPLETE_;
            me->BLINKYCHOICE_MODE_COMPLETION_EVENT_.completion_evt.substate = NULL;  // Comodo functionality not implemented
            QF_publish_(&(me->BLINKYCHOICE_MODE_COMPLETION_EVENT_.base_evt));
            return Q_HANDLED();


    }
    return Q_SUPER(&QHsm_top);
}

/**
 * on state definition
 */
QState blinkyChoice_mode_on (blinkyChoice_mode *me, QEvt const *e) {
    switch (e->sig) {
        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MODE_ON;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_TURN_OFF_SIG:
            return Q_TRAN(&blinkyChoice_mode_off);


    }
    return Q_SUPER(&QHsm_top);
}

/**
 * unnamedState0 state definition
 */
QState blinkyChoice_mode_unnamedState0 (blinkyChoice_mode *me, QEvt const *e) {
    switch (e->sig) {
        case Q_ENTRY_SIG:
            me->myState = BLINKYCHOICE_MODE_UNNAMEDSTATE0;
            return Q_HANDLED();

        case Q_EXIT_SIG:
            return Q_HANDLED();

        case BLINKYCHOICE_WIF_HEY_SIG:
            blinkyChoice_mode_impl_hello(me->impl);
            if (blinkyChoice_mode_impl_heyoooo(me->impl, GUARD1, GUARD2)){
                return Q_TRAN(&blinkyChoice_mode_on);
            }
            if (blinkyChoice_mode_impl_hyiiiqqq(me->impl)){
                if (blinkyChoice_mode_impl_uuuueee(me->impl)){
                    blinkyChoice_mode_impl_hello(me->impl);
                    blinkyChoice_mode_impl_hiiiii(me->impl, AWC_2, AWWWW);
                    QEvt *newEv0 = Q_NEW(QEvt, BLINKYCHOICE_WIF_HEY_SIG);
                    QF_publish_(newEv0);
                    QEvt *newEv1 = Q_NEW(QEvt, BLINKYCHOICE_TURN_ON_SIG);
                    QF_publish_(newEv1);
                    me->BLINKYCHOICE_MODE_COMPLETION_EVENT_.completion_evt.super.sig = _SIG_BLINKYCHOICE_MODE_COMPLETE_;
                    me->BLINKYCHOICE_MODE_COMPLETION_EVENT_.completion_evt.substate = NULL;  // Comodo functionality not implemented
                    QF_publish_(&(me->BLINKYCHOICE_MODE_COMPLETION_EVENT_.base_evt));
                    return Q_TRAN(&blinkyChoice_mode_finalState0);
                }
                else {
                    return Q_TRAN(&blinkyChoice_mode_on);
                }
            }

            return Q_HANDLED();


    }
    return Q_SUPER(&QHsm_top);
}
