#pragma once
#include "BinarniRelace.h"


/**
Trida predstavujici tranzitivni uzaver dedici z binarni relace, jelikoz tranzitivni uzaver je pouze specialni
pripad binarni relace a to, ze existujou vsechny vztahy
*/
class TranzitivniUzaver : public BinarniRelace
{
public:
	TranzitivniUzaver (BinarniRelace* x);
};

