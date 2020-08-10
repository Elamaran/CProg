#include<stdio.h>

const float START_LIMIT =0; //0 deg C low limit
const float UPPER_LIMIT =100; //100 deg C upper limit

float get_start_temperature(float);
float get_end_temperature(float);
float get_step_temperature(float,float);


void main()
{
    float start_value = START_LIMIT;
    float end_value = UPPER_LIMIT;
    float step_value = START_LIMIT;
    float i=0;
    float temperature_F = 0;
    printf("\n--------------------\nWelcome to temperature table App\n");
    
    start_value = get_start_temperature(START_LIMIT);
    end_value = get_end_temperature(UPPER_LIMIT);
    step_value = get_step_temperature(start_value, end_value);

    printf("Entered values,\nStart Value = %f\nEnd value = %f\nStep value = %f\n",start_value,end_value,step_value);

    //TODO -> generate all the values in the given range and print them as a table

    printf("Celcius\t\tFahrenheit\n");
    printf("-------\t\t----------\n");

    for (i = start_value; i < UPPER_LIMIT; i+=step_value)
    {
        temperature_F = (i*9/5)+32;  //Celcius to Fahrenheit

        printf("%f\t%f\n",i,temperature_F);      
     
    }
    

    getchar();
}

float get_start_temperature (float start_limit)
{
    int valid=0;
    float st_val = -1;

    while(!valid)
    {
        printf("Enter a starting temperature value above %0.0f degC starting limit: ", start_limit);
        scanf("%f",&st_val);
        if (st_val >= start_limit) 
        {
            valid =1; //exit loop since a validate value is entered
        } else
        {
            printf("\n Entered value is lower than start limit!!\n");
            valid = 0; //don't exit a loop since invalid value is entered           
        }
    }// obtained a valid starting value
    return st_val;
}

float get_end_temperature (float upper_limit)
{
    int valid=0;
    float end_val = -1;

    while(!valid)
    {
        printf("Enter an ending temperature value below %f degC upper limit: ", upper_limit);
        scanf("%f",&end_val);
        if (end_val <= upper_limit) 
        {
            valid =1; //exit loop since a validate value is entered
        } else
        {
            printf("\n Entered value is higher than upper limit!!\n");
            valid = 0; //don't exit a loop since invalid value is entered           
        }
    }// obtained a valid ending value
    
    return end_val;
}

float get_step_temperature (float start_value,float end_value)
{
    int valid=0;
    float step_val = -1;
    int is_with_in_limit = 0;

    while(!valid)
    {
        printf("Enter a step temperature value within %f degC lower value and %f degC upper value: ", start_value, end_value);
        scanf("%f",&step_val);
        is_with_in_limit = (start_value <= step_val) & (step_val <= (end_value-start_value));

        if (is_with_in_limit)
        {
            valid =1; //exit loop since a validate value is entered
        } else
        {
            printf("\n Entered value is not within the limit!!\n");
            valid = 0; //don't exit a loop since invalid value is entered           
        }
    }// obtained a valid ending value

    return step_val;
}