#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_countryCode_iso3166alpha3_deprecated">
        <xs:restriction base="xs:string">
            <xs:pattern value="[A-Z]{3}"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_countryCode_iso3166alpha3_deprecated(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_countryCode_iso3166alpha3_deprecated) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, AFG , _SC_AFG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, AGO , _SC_AGO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, AIA , _SC_AIA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ALB , _SC_ALB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, AND , _SC_AND) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ARE , _SC_ARE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ARG , _SC_ARG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ARM , _SC_ARM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ATG , _SC_ATG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, AUS , _SC_AUS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, AUT , _SC_AUT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, AZE , _SC_AZE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BDI , _SC_BDI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BEL , _SC_BEL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BEN , _SC_BEN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BFA , _SC_BFA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BGD , _SC_BGD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BGR , _SC_BGR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BHR , _SC_BHR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BHS , _SC_BHS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BIH , _SC_BIH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BLR , _SC_BLR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BLZ , _SC_BLZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BMU , _SC_BMU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BOL , _SC_BOL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BRA , _SC_BRA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BRB , _SC_BRB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BRN , _SC_BRN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BTN , _SC_BTN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, BWA , _SC_BWA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CAF , _SC_CAF) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CAN , _SC_CAN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CHE , _SC_CHE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CHL , _SC_CHL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CHN , _SC_CHN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CIV , _SC_CIV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CMR , _SC_CMR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, COD , _SC_COD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, COG , _SC_COG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, COK , _SC_COK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, COL , _SC_COL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, COM , _SC_COM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CPV , _SC_CPV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CRI , _SC_CRI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CUB , _SC_CUB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CYM , _SC_CYM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CYP , _SC_CYP) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, CZE , _SC_CZE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, DEU , _SC_DEU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, DJI , _SC_DJI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, DMA , _SC_DMA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, DNK , _SC_DNK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, DOM , _SC_DOM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, DZA , _SC_DZA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ECU , _SC_ECU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, EGY , _SC_EGY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ERI , _SC_ERI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ESH , _SC_ESH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ESP , _SC_ESP) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, EST , _SC_EST) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ETH , _SC_ETH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, FIN , _SC_FIN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, FJI , _SC_FJI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, FLK , _SC_FLK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, FRA , _SC_FRA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, FRO , _SC_FRO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, FSM , _SC_FSM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GAB , _SC_GAB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GBR , _SC_GBR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GEO , _SC_GEO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GGY , _SC_GGY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GHA , _SC_GHA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GIB , _SC_GIB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GIN , _SC_GIN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GMB , _SC_GMB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GNB , _SC_GNB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GNQ , _SC_GNQ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GRC , _SC_GRC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GRD , _SC_GRD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GRL , _SC_GRL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GTM , _SC_GTM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, GUY , _SC_GUY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, HND , _SC_HND) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, HRV , _SC_HRV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, HTI , _SC_HTI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, HUN , _SC_HUN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, IDN , _SC_IDN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, IMN , _SC_IMN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, IND , _SC_IND) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, IOT , _SC_IOT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, IRL , _SC_IRL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, IRN , _SC_IRN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, IRQ , _SC_IRQ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ISL , _SC_ISL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ISR , _SC_ISR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ITA , _SC_ITA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, JAM , _SC_JAM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, JEY , _SC_JEY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, JOR , _SC_JOR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, JPN , _SC_JPN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KAZ , _SC_KAZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KEN , _SC_KEN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KGZ , _SC_KGZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KHM , _SC_KHM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KIR , _SC_KIR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KNA , _SC_KNA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KOR , _SC_KOR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, KWT , _SC_KWT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LAO , _SC_LAO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LBN , _SC_LBN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LBR , _SC_LBR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LBY , _SC_LBY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LCA , _SC_LCA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LIE , _SC_LIE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LKA , _SC_LKA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LSO , _SC_LSO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LTU , _SC_LTU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LUX , _SC_LUX) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, LVA , _SC_LVA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MAR , _SC_MAR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MCO , _SC_MCO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MDA , _SC_MDA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MDG , _SC_MDG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MDV , _SC_MDV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MEX , _SC_MEX) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MHL , _SC_MHL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MKD , _SC_MKD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MLI , _SC_MLI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MLT , _SC_MLT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MMR , _SC_MMR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MNE , _SC_MNE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MNG , _SC_MNG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MOZ , _SC_MOZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MRT , _SC_MRT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MSR , _SC_MSR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MUS , _SC_MUS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MWI , _SC_MWI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, MYS , _SC_MYS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NAM , _SC_NAM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NER , _SC_NER) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NGA , _SC_NGA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NIC , _SC_NIC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NIU , _SC_NIU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NLD , _SC_NLD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NOR , _SC_NOR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NPL , _SC_NPL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NRU , _SC_NRU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, NZL , _SC_NZL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, OMN , _SC_OMN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PAK , _SC_PAK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PAN , _SC_PAN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PCN , _SC_PCN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PER , _SC_PER) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PHL , _SC_PHL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PLW , _SC_PLW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PNG , _SC_PNG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, POL , _SC_POL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PRK , _SC_PRK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PRT , _SC_PRT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, PRY , _SC_PRY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, QAT , _SC_QAT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ROU , _SC_ROU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, RUS , _SC_RUS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, RWA , _SC_RWA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SAU , _SC_SAU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SDN , _SC_SDN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SEN , _SC_SEN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SGP , _SC_SGP) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SGS , _SC_SGS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SHN , _SC_SHN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SLB , _SC_SLB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SLE , _SC_SLE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SLV , _SC_SLV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SMR , _SC_SMR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SOM , _SC_SOM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SRB , _SC_SRB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SSD , _SC_SSD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, STP , _SC_STP) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SUR , _SC_SUR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SVK , _SC_SVK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SVN , _SC_SVN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SWE , _SC_SWE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SWZ , _SC_SWZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SYC , _SC_SYC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, SYR , _SC_SYR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TCA , _SC_TCA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TCD , _SC_TCD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TGO , _SC_TGO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, THA , _SC_THA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TJK , _SC_TJK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TKL , _SC_TKL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TKM , _SC_TKM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TLS , _SC_TLS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TON , _SC_TON) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TTO , _SC_TTO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TUN , _SC_TUN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TUR , _SC_TUR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TUV , _SC_TUV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TWN , _SC_TWN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, TZA , _SC_TZA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, UGA , _SC_UGA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, UKR , _SC_UKR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, URY , _SC_URY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, USA , _SC_USA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, UZB , _SC_UZB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, VAT , _SC_VAT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, VCT , _SC_VCT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, VEN , _SC_VEN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, VGB , _SC_VGB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, VNM , _SC_VNM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, VUT , _SC_VUT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, WSM , _SC_WSM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, XKX , _SC_XKX) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, YEM , _SC_YEM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ZAF , _SC_ZAF) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ZMB , _SC_ZMB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha3_deprecated, ZWE , _SC_ZWE) \
    EMPTY_COMMAND

struct e_countryCode_iso3166alpha3_deprecated : public _e_base
{
    _OD_STRING_ENUM_e_countryCode_iso3166alpha3_deprecated(DECLARE)

public:
    e_countryCode_iso3166alpha3_deprecated()
    {
        this->value = 0; // Default value
    }
};
}
