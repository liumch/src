/*        Generated by TAPENADE     (INRIA, Tropics team)
    Tapenade 3.6 (r4512) -  3 Aug 2012 15:11
*/
#include "cstd.h"
/**** added to compile */
#include "adBuffer.h"
/*
  Differentiation of acd_2d_4 in reverse (adjoint) mode:
   gradient     of useful results: **up
   with respect to varying inputs: **csq **uc **up
   RW status of diff variables: **csq:out **uc:out **up:in-out
   Plus diff mem management of: csq:in *csq:in uc:in *uc:in up:in
                *up:in
*/
void acd_2d_4_b(float **uc, float **ucb, float **up, float **upb, float **csq,
        float **csqb, int *s, int *e, float c0, float *c1, float *c2, 
        int *lbc, int *rbc) {
    int i0, i1;

    int branch;
    float tmpb;
    float tmp0b;
    float tempb;
    // boundary conditions - note that uc[-1][i]=0 etc.
    if (lbc[1])
        pushcontrol1b(0);
    else
        pushcontrol1b(1);
    if (rbc[1])
        pushcontrol1b(0);
    else
        pushcontrol1b(1);
    if (lbc[0])
        pushcontrol1b(0);
    else
        pushcontrol1b(1);
    if (rbc[0])
        for (i1 = e[1]; i1 > s[1]-1; --i1) {
            upb[i1][e[0]] = upb[i1][e[0]] - upb[i1][e[0] + 2];
            upb[i1][e[0] + 2] = 0.0;
        }
    popcontrol1b(&branch);
    if (branch == 0)
        for (i1 = e[1]; i1 > s[1]-1; --i1) {
            upb[i1][s[0]] = upb[i1][s[0]] - upb[i1][s[0] - 2];
            upb[i1][s[0] - 2] = 0.0;
        }
    popcontrol1b(&branch);
    if (branch == 0)
        for (i0 = e[0]; i0 > s[0]-1; --i0) {
            tmp0b = upb[e[1] + 2][i0];
            upb[e[1] + 2][i0] = 0.0;
            upb[e[1]][i0] = upb[e[1]][i0] - tmp0b;
        }
    popcontrol1b(&branch);
    if (branch == 0)
        for (i0 = e[0]; i0 > s[0]-1; --i0) {
            tmpb = upb[s[1] - 2][i0];
            upb[s[1] - 2][i0] = 0.0;
            upb[s[1]][i0] = upb[s[1]][i0] - tmpb;
        }
    **csqb = 0.0;
    for (i1 = e[1]; i1 > s[1]-1; --i1)
        for (i0 = e[0]; i0 > s[0]-1; --i0) {
            tempb = csq[i1][i0]*upb[i1][i0];
            ucb[i1][i0] = ucb[i1][i0] + c0*tempb + 2.0*upb[i1][i0];
            csqb[i1][i0] = csqb[i1][i0] + (c0*uc[
                i1][i0]+c1[0]*(uc[i1][i0+1]+uc[i1][i0-1])+c1[1]*(uc[i1+1][i0]+
                uc[i1-1][i0])+c2[0]*(uc[i1][i0+2]+uc[i1][i0-2])+c2[1]*(uc[i1+2
                ][i0]+uc[i1-2][i0]))*upb[i1][i0];
            ucb[i1][i0 + 1] = ucb[i1][i0 + 1] + c1[0]*tempb;
            ucb[i1][i0 - 1] = ucb[i1][i0 - 1] + c1[0]*tempb;
            ucb[i1 + 1][i0] = ucb[i1 + 1][i0] + c1[1]*tempb;
            ucb[i1 - 1][i0] = ucb[i1 - 1][i0] + c1[1]*tempb;
            ucb[i1][i0 + 2] = ucb[i1][i0 + 2] + c2[0]*tempb;
            ucb[i1][i0 - 2] = ucb[i1][i0 - 2] + c2[0]*tempb;
            ucb[i1 + 2][i0] = ucb[i1 + 2][i0] + c2[1]*tempb;
            ucb[i1 - 2][i0] = ucb[i1 - 2][i0] + c2[1]*tempb;
            upb[i1][i0] = -upb[i1][i0];
        }
}