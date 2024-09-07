#ifndef _UTIL_HPP_
#define _UTIL_HPP_

#define BIG_TO_LITTLE(num) (((num >> 24) & 0xFF) | ((num << 8) & 0xFF0000) | ((num >> 8) & 0xFF00) | ((num << 24) & 0xFF000000))

#define ESRI_INTEGER 4
#define ESRI_DOUBLE 8

#endif
