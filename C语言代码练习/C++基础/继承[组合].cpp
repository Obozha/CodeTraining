class Vehicle{
	//...
} // ������ 

class Motor {
	// �����
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
