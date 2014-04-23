#ifndef __THERMOCOUPLE_H

/**
 * Returns temperature as a function of the ambient temperature and measured thermocouple voltage
 **/
long thermocoupleConvertWithCJCompensation(unsigned long microvoltsMeasured, unsigned long ambient);

/**
 * Returns temperature equivalent the voltage provided in microvolts
 */
long thermocoupleMvToC(unsigned long microvolts);

#endif
