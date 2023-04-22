/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

Weather weather_from_file(FILE* file)
{
    Weather weather;

    /* Completar aqui */
    int average=0,max=0,min=0;
    unsigned int pre=0u,moi=0u,rai=0u;
    
    int res = fscanf(file,"%d %d %d %u %u %u",&average,&max,&min,&pre,&moi,&rai);
    
    if(res!=AMOUNT_OF_WEATHER_VARS){
      fprintf(stdout,"Invalid array.");
    }

    weather._average_temp = average;
    weather._max_temp = max;
    weather._min_temp = min;
    weather._pressure = pre;
    weather._moisture = moi;
    weather._rainfall = rai;

    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
