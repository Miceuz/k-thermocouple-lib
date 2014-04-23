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
