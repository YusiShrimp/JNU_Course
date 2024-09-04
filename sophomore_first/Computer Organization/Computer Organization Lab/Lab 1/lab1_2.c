/*
Instructions -

To run this program - first compile to crete an executable, 
then run the executable code.

Type the following in the Linux console/shell to compile and make an executable using the gcc complier-

gcc lab1.c -o lab1

To run the executable named "lab1", type the following-

./lab1
*/


#include <stdio.h> //For input/output
#include <stdint.h> //For int32_t
#include <sys/time.h> //For gettimeofday() function

int main()
{
	int int_var; //Tag 1

	struct timeval this_instant;
	double time_stamp;
	

	FILE *my_file_pointer;
	if ( (my_file_pointer = fopen("lab1_2_out.txt", "w")) == NULL)
	{
		printf("Error opening the file, so exiting\n");
		exit(1);
	}

	gettimeofday(&this_instant,0);
	time_stamp = this_instant.tv_sec;

	//Code segment for file I/O
	fprintf(my_file_pointer, "This program was executed at time : %d secs\n", (int)time_stamp);

	fprintf(my_file_pointer, "The sizes of different data type for this machine and compiler are -\n");
	fprintf(my_file_pointer, "int data type is %d bytes or %d bits long\n",sizeof(int_var), sizeof(int_var)*8 ); 
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(signed char), sizeof(signed char)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(unsigned char), sizeof(unsigned char)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(short), sizeof(short)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(unsigned short), sizeof(unsigned short)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(int), sizeof(int)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(unsigned), sizeof(unsigned)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(long), sizeof(long)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(unsigned long), sizeof(unsigned long)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(int32_t), sizeof(int32_t)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(uint32_t), sizeof(uint32_t)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(int64_t), sizeof(int64_t)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(uint64_t), sizeof(uint64_t)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(char*), sizeof(char*) * 8);
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(float), sizeof(float)*8 );
    fprintf(my_file_pointer, "double data type is %d bytes or %d bits long\n",sizeof(double), sizeof(double)*8 );

	//Code segment for console I/O, this can be used instead of the file I/O
	printf("This program was executed at time : %d secs\n", (int)time_stamp);

	printf("The sizes of different data type for this machine and compiler are -\n");
	printf("int data type is %d bytes or %d bits long\n",sizeof(int_var), sizeof(int_var)*8 );  //Tag 2
    printf( "double data type is %d bytes or %d bits long\n", sizeof(signed char), sizeof(signed char) * 8 );
    printf( "double data type is %d bytes or %d bits long\n", sizeof(unsigned char), sizeof(unsigned char) * 8 );
    printf( "double data type is %d bytes or %d bits long\n", sizeof(short), sizeof(short) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(unsigned short), sizeof(unsigned short) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(int), sizeof(int) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(unsigned), sizeof(unsigned) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(long), sizeof(long) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(unsigned long), sizeof(unsigned long) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(int32_t), sizeof(int32_t) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(uint32_t), sizeof(uint32_t) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(int64_t), sizeof(int64_t) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(uint64_t), sizeof(uint64_t) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(char*), sizeof(char*) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(float), sizeof(float) * 8);
    printf( "double data type is %d bytes or %d bits long\n", sizeof(double), sizeof(double) * 8);
	
	fclose(my_file_pointer); //To close the output file, mandatory to actually get an output !

	return 0;
}
