


double theta = 5;
double alpha = 5;
double gamma = 4;


static double Rf[4][4] = {	
						{ (cos(alpha)*cos(gamma))+(sin(alpha)*sin(theta)*sin(gamma)), (cos(alpha)*-sin(gamma))+(cos(gamma)*sin(alpha)*sin(theta)), sin(alpha)*cos(theta), 0},
						{ cos(theta)*sin(gamma), cos(gamma)*cos(theta),-sin(theta) -sin(theta), 0},
						{ (-sin(alpha)*cos(gamma))+(cos(alpha)*sin(theta)*sin(gamma)), (sin(alpha)*sin(gamma))+(cos(alpha)*sin(theta)*cos(gamma)), cos(alpha)*cos(theta), 0},
						{ 0, 0, 0, 1}
			};
			
			
			
			
