#include "Contour.h"

Contour::Contour(){

		sql::Connection *con;
		/* Create a connection */
		sql::Driver *driver = get_driver_instance();
		con = driver->connect("localhost","root","isen29");

		/* Connect to the MySQL database */
		con->setSchema("db_projet");

		//setlocale(LC_ALL,"C");

		sql::Statement *stmt = con->createStatement();
 		sql::ResultSet *res = stmt->executeQuery("select * from contour");
		res->next();

		while(res->next()){
			point.push_back(Point(res->getInt(1),res->getDouble(2),res->getDouble(3)));
		}

		delete con;

}

