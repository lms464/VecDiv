/* VecDivCmd
 * The idea is a wrapper to speed up list divition 
 * See if it works!
 */
#include <iostream>
#include <math.h>
#include "/Censere/pkgs/tk-8.6.8-hbc83047_0/include/tcl.h"
#include <vector>

extern "C" {

	int VecDivCmd( ClientData clientData, Tcl_Interp *interp, int objc, Tcl_Obj *CONST objv[]) 
	{
		Tcl_Obj *resultptr;
		Tcl_Obj **listv;

		int listc1;
		int listc2;

		if (objc != 3) 
		{
			Tcl_WrongNumArgs(interp,2,objv,
				"Usage : vecdiv list1 list2");
			return TCL_ERROR;
		}

		if (Tcl_ListObjGetElements(interp, objv[objc-2], 
			&listc1, &listv) !=TCL_OK )
		{
	        Tcl_SetResult(interp, (char *) "error parsing argument",
	         TCL_STATIC);
			return -1;			
		}

		std::vector<double> Arr1(listc1, 0);
		std::vector<double> Arr2(listc1, 0);

		for (int i=0; i<listc1; i++) {
			if (Tcl_GetDoubleFromObj(interp, listv[i], &Arr1[i]) != TCL_OK)
			{
				Tcl_SetResult(interp, 
			    	(char *) "error parsing elements from list ", TCL_STATIC);
				return -1;	
			}
		}

		if (Tcl_ListObjGetElements(interp, objv[objc-1], 
			&listc2, &listv) !=TCL_OK )
		{
			 Tcl_SetResult(interp, 
			    (char *) "error parsin element ", TCL_STATIC);
			return -1;			
		}

		if (listc1 != listc2) {
			std::cout << "Lists are different Lenght" << std::endl;
		}

		for (int i=0; i<listc1; i++) {
			if (Tcl_GetDoubleFromObj(interp, listv[i], &Arr2[i]) != TCL_OK)
			{
				Tcl_SetResult(interp, 
			    	(char *) "error parsing elements from list ", TCL_STATIC);
				return -1;	
			}
		}

		for (int i=0; i<listc1; i++) {
				Tcl_SetDoubleObj(listv[i],Arr1[i] / Arr2[i]);
		}

		resultptr = Tcl_GetObjResult(interp);
		Tcl_SetListObj(resultptr, listc1, listv);
		return TCL_OK;
	}


	int Vecdiv_Init( Tcl_Interp *interp ) 
	{
		Tcl_CreateObjCommand(interp, "vecdiv", VecDivCmd, 
			(ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
		return TCL_OK;
	}

}