#include "OtherFunctions.h"

bool ctrlhandler(DWORD fdwctrltype)
{
	switch (fdwctrltype)
	{
		// handle the ctrl-c signal.
	case CTRL_C_EVENT:
		//printf( "ctrl-c event\n\n" );
		//return( true );
		// ctrl-close: confirm that the user wants to exit.
	case CTRL_CLOSE_EVENT:
		//printf( "ctrl-close event\n\n" );
		//return( true );
		// pass other signals to the next handler.
	case CTRL_BREAK_EVENT:
		//printf( "ctrl-break event\n\n" );
		//return false;
	case CTRL_LOGOFF_EVENT:
		//printf( "ctrl-logoff event\n\n" );
		//return false;
	case CTRL_SHUTDOWN_EVENT:
		//printf( "ctrl-shutdown event\n\n" );
		//return false;
		//ê¥óù
		return true;
	default:
		return false;
	}
}

double Distance3D(Coordinate<double> A, Coordinate<double> B) {
	double Distance;
	Distance = sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2));
	return Distance;
}
