/* VecDivCmd
 * The idea is a wrapper to speed up list divition 
 * See if it works!
 */
#include <iostream>
#include <math.h>
#include "/Censure/pkgs/tk-8.6.8-hbc83047_0/include/tcl.h" //Needs to be flexible
#include <vector>

extern "C" {

	int VecDivCmd( ClientData clientData, Tcl_Interp *interp, 
		int objc, Tcl_Obj *CONST objv[]) 
	{
		//Intsntiate Tcl Obj
		Tcl_Obj *resultptr;
		int listc1;
		int listc2
		Tcl_Obj **listv;

		//Set it to only take 2 arguments
		if (objc != 3) 
		{
			Tcl_WrongNumArgs(interp,2,objv,
				"Usage : vecdiv list1 list2");
			return TCL_ERROR;
		}

		// List value 1 extraction
		if (Tcl_ListObjGetElements(interp, objv[objc-2], 
			&listc1, &listv) !=TCL_OK )
		{
			std::cout<< "Argument not a valid list."<<std::endl;
			std::cout<<std::endl;
			return TCL_ERROR;			
		}

		// set up arrays to manage the lists
		std::vector<double> Arr1(listc, 0);
		std::vector<double> Arr2(listc, 0);
		std::vector<double> Out(listc, 0);

		//get list 1
		for (int i=0; i<listc; i++) {
			if (Tcl_GetDoubleFromObj(interp, listv[i], &Arr1[i]) != TCL_OK)
			{
				std::cout << "Input was not a double."<<std::endl;
				std::cout << std::endl;
				return TCL_ERROR;
			}
		}

		// List value 2 extraction

		if (Tcl_ListObjGetElements(interp, objv[objc-1], 
			&listc2, &listv) !=TCL_OK )
		{
			std::cout<< "Argument not a valid list."<<std::endl;
			std::cout<<std::endl;
			return TCL_ERROR;			
		}

		if (listc1 != listc2) {
			std::cout << "Lists are different Lenght" << std::endl;

		}

		//get lists 2
		for (int i=0; i<listc; i++) {
			if (Tcl_GetDoubleFromObj(interp, listv[i], &Arr2[i]) != TCL_OK)
			{
				std::cout << "Input was not a double."<<std::endl;
				std::cout << std::endl;
			}
		}

		//The division
		for (int i=0; i<listc; i++) {
				Out[i] = Arr1[i] / Arr2[i];
				Tcl_SetDoubleObj(listv[i],Out[i]);
		}
		//Returns values
		resultptr = Tcl_GetObjResult(interp);
		Tcl_SetListObj(resultptr, listc, listv);
		return TCL_OK;
	};


	int Vecdiv_Init( Tcl_Interp *interp ) 
	{
		Tcl_CreateObjCommand(interp, "vecdiv", VecDivCmd, 
			(ClientData) NULL, (Tcl_CmdDeleteProc *) NULL);
		return TCL_OK;
	}

}