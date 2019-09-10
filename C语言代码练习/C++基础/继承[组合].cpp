class Vehicle{
	//...
} // 车辆类 

class Motor {
	// 马达类
}

class Car:public Vehicle{
	public:
		Motor motor;
}; 

void vehicleFn(Vehicle& v);
void motorFn(Motor& m);

int main(){
	Car c;
	VehicleFn(c);     //ok
	motorFn(c);	  	  //error
	motorFn(c.motor); // ok
}
