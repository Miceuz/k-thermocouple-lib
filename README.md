k-thermocouple-lib
==================

Converts thermocouple voltage to temperature with linearization and cold junction compensation. 

The library uses a 65 entry lookup table and an interpolation to convert from K-type thermocouple voltage to temperature in degrees Celsius and back. The lookup table is based on [NIST](http://srdata.nist.gov/its90/main/its90_main_page.html) data, points for the lookup table were selected by hand according to the most nonlinear places in k-thermocouple response, to minimaze the error. 

Code is written using fixed point arithmetic and is suitable for embedded applications. 

![](https://github.com/Miceuz/k-thermocouple-lib/raw/master/plots/lookup-table-selection.png)


Accuracy
--------
![](https://github.com/Miceuz/k-thermocouple-lib/raw/master/plots/error-voltage-vs-temperature.png)
![](https://github.com/Miceuz/k-thermocouple-lib/raw/master/plots/error-temperature-vs-voltage.png)
