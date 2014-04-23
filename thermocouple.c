#include <stdio.h>

#define POINTS_COUNT 65

typedef	struct {
	long temp;
	unsigned long microvolts;
} temp_point;

static temp_point thermocouplePoints[] = {
{ 0 , 0 },
{ 10000 , 397 },
{ 20000 , 798 },
{ 30000 , 1203 },
{ 40000 , 1612 },
{ 50000 , 2023 },
{ 60000 , 2436 },
{ 79000 , 3225 },
{ 98000 , 4013 },
{ 116000 , 4756 },
{ 134000 , 5491 },
{ 139000 , 5694 },
{ 155000 , 6339 },
{ 172000 , 7021 },
{ 193000 , 7859 },
{ 212000 , 8619 },
{ 231000 , 9383 },
{ 250000 , 10153 },
{ 269000 , 10930 },
{ 288000 , 11712 },
{ 307000 , 12499 },
{ 326000 , 13290 },
{ 345000 , 14084 },
{ 364000 , 14881 },
{ 383000 , 15680 },
{ 402000 , 16482 },
{ 421000 , 17285 },
{ 440000 , 18091 },
{ 459000 , 18898 },
{ 478000 , 19707 },
{ 497000 , 20516 },
{ 516000 , 21326 },
{ 535000 , 22137 },
{ 554000 , 22947 },
{ 573000 , 23757 },
{ 592000 , 24565 },
{ 611000 , 25373 },
{ 630000 , 26179 },
{ 649000 , 26983 },
{ 668000 , 27784 },
{ 687000 , 28584 },
{ 706000 , 29380 },
{ 725000 , 30174 },
{ 744000 , 30964 },
{ 763000 , 31752 },
{ 782000 , 32536 },
{ 801000 , 33316 },
{ 820000 , 34093 },
{ 839000 , 34867 },
{ 858000 , 35637 },
{ 877000 , 36403 },
{ 896000 , 37166 },
{ 915000 , 37925 },
{ 934000 , 38680 },
{ 953000 , 39432 },
{ 972000 , 40180 },
{ 991000 , 40924 },
{ 1010000 , 41665 },
{ 1029000 , 42402 },
{ 1048000 , 43134 },
{ 1067000 , 43863 },
{ 1086000 , 44588 },
{ 1105000 , 45308 },
{ 1124000 , 46024 },
{ 1143000 , 46735 },
{ 1200000 , 48838 }
};

static inline unsigned long interpolate(unsigned long val, unsigned long rangeStart, unsigned long rangeEnd, unsigned long valStart, unsigned long valEnd) {
    return rangeStart + (rangeEnd - rangeStart) * (val - valStart) / (valEnd - valStart);
}

static inline unsigned long interpolateVoltage(unsigned long temp, unsigned char i){
    return interpolate(temp, thermocouplePoints[i-1].microvolts, thermocouplePoints[i].microvolts, thermocouplePoints[i-1].temp, thermocouplePoints[i].temp);
}

static inline unsigned long interpolateTemperature(unsigned long microvolts, unsigned char i){
    return interpolate(microvolts, thermocouplePoints[i-1].temp, thermocouplePoints[i].temp, thermocouplePoints[i-1].microvolts, thermocouplePoints[i].microvolts);
}

/**
 * Returns the index of the first point whose temperature value is greater than argument
 **/
static inline unsigned char searchTemp(unsigned long temp) {
	unsigned char i;
	for(i = 0; i < POINTS_COUNT; i++) {
		if(thermocouplePoints[i].temp > temp) {
			return i;
		}
	}
	return POINTS_COUNT-1;
}

/**
 * Returns the index of the first point whose microvolts value is greater than argument
 **/
static inline unsigned char searchMicrovolts(unsigned long microvolts) {
	unsigned char i;
	for(i = 0; i < POINTS_COUNT; i++) {
		if(thermocouplePoints[i].microvolts > microvolts) {
			return i;
		}
	}
	return POINTS_COUNT-1;
}

/**
 * Returns temperature as a function of the ambient temperature and measured thermocouple voltage.
 * Currently only positive ambient temperature is supported
 **/
long thermocoupleConvertWithCJCompensation(unsigned long microvoltsMeasured, unsigned long ambient) {
	//convert ambient temp to microvolts
	//and add them to the thermocouple measured microvolts 
	unsigned long microvolts = microvoltsMeasured + interpolateVoltage(ambient, searchTemp(ambient));
	//look up microvolts in The Table and interpolate
	return interpolateTemperature(microvolts, searchMicrovolts(microvolts));
}

/**
 * Returns temperature, equivalent to the voltage provided in microvolts
 */
long thermocoupleMvToC(unsigned long microvolts) {
	return interpolateTemperature(microvolts, searchMicrovolts(microvolts));
}

/******************************************************************************
 * Additional info
 * ****************************************************************************
 * Changelog:
 * - v. 1.0 (initial release) 2014-04-24 by Albertas Mickėnas mic@wemakethings.net
 *
 * ****************************************************************************
 * Bugs, feedback, questions and modifications can be posted on the github page
 * on https://github.com/Miceuz/k-thermocouple-lib/
 * ****************************************************************************
 * - LICENSE -
 * GNU GPL v2 (http://www.gnu.org/licenses/gpl.txt)
 * This program is free software. You can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 * ****************************************************************************
 */

//~ void main(int argc, char **argv) {
	//~ unsigned long i = 0;
	//~ for(i = 0; i < 16383; i++) {
		//~ unsigned long voltage = 5000000 / 16384 * i / 101;
		//~ printf("%ld\n", thermocoupleMvToC(voltage));
	//~ }
	//~ for(i = 0; i < 1280000; i+=1000) {
		//~ printf("%ld\n", interpolateVoltage(i, searchTemp(i)));
	//~ }
//~ }

