/*
This program sounds the bell when driver is on seat AND haven't closed the doors. Use the general framework and the function shells, replace the code inside  the control_action() function with your own code.

Note: This code is designed to run in an infinite loop to mimic a real control system.
If you prefer to read the inputs from a file, modify the code appropriately to terminate the loop when all the inputs have been processed.

run this file as : gcc filename.c -o executableName

*/


#include <stdio.h> //This is useful to do i/o to test the code 
#include<stdlib.h>

unsigned int driver_on_seat;
unsigned int driver_seat_belt_fasten;
unsigned int doors_closed;
unsigned int engine_running;
unsigned int key_in_car;
unsigned int car_moving;
unsigned int bp;
unsigned int brake;
unsigned int bell;
unsigned int door_lock;

int currentline = 0;

void read_inputs_from_ip_if() {

	char data[10];
	FILE* file;
	file = fopen("data.txt", "r");
	if (file == NULL)
	{
		printf("Fail to open the file!\n");
		exit(0);
	}
	for (int j = 0; j < currentline; j++) {
		fscanf(file, "%*s");
	}

	if ((fscanf(file, "%s", &data) == -1)) {
		exit(0); //The file had reached the end
	}

	printf("Situation %d:\n", currentline + 1);

	for (int i = 0; i < 7; i++)
	{
		switch (i)
		{
		case 0:
			driver_on_seat = (int)data[0] - 48;
			break;
		case 1:
			driver_seat_belt_fasten = (int)data[1] - 48;
			break;
		case 2:
			doors_closed = (int)data[2] - 48;
			break;
		case 3:
			engine_running = (int)data[3] - 48;
			break;
		case 4:
			key_in_car = (int)data[4] - 48;
			break;
		case 5:
			car_moving = (int)data[5] - 48;
			break;
		case 6:
			bp = (int)data[6] - 48;
			break;
		default:
			break;
		}
	}
	currentline++;
	fclose(file);
}

void write_output_to_op_if() {

	printf("BELL: %d\n", bell);
	printf("Door Lock: %d\n", door_lock);
	printf("Brake: %d\n", brake);
}


//The code segment which implements the decision logic
void control_action() {
	// 需求1：驾驶员未系好安全带并启动发动机时，发出警报
	if (driver_on_seat && !driver_seat_belt_fasten && engine_running && key_in_car && doors_closed) {
		bell = 1;
	}

	//需求2：驾驶员在未关闭所有车门的情况下启动汽车时，发出警报
	else if (driver_on_seat && !doors_closed && engine_running)
		bell = 1;

	else {
		bell = 0;
	}

	//需求3：情况恢复正常，bell立即关闭
	if (driver_on_seat && doors_closed && key_in_car && driver_seat_belt_fasten)
		bell = 0;

	// 需求4：司机下车但钥匙仍在发动机内，且未要求锁门时，不锁门
	if (!driver_on_seat && key_in_car && doors_closed) {
		door_lock = 0;
	}
	else if (driver_on_seat && doors_closed)
	{
		door_lock = 1;
	}


	// 需求5：刹车踏板按下时刹车处于啮合状态，否则松开
	if (car_moving && bp) {
		brake = 1;
	}
	else if (car_moving && !bp) {
		brake = 0;
	}
	else if (!car_moving) {
		brake = 0;
	}



}

/* ---     You should not have to modify anything below this line ---------*/

int main(int argc, char* argv[])
{

	/*The main control loop which keeps the system alive and responsive for ever,
	until the system is powered off */
	for (; ; )
	{
		read_inputs_from_ip_if();
		control_action();
		write_output_to_op_if();

	}

	return 0;
}
