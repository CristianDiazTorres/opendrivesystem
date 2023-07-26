#pragma once

#include "XODR/OpenDRIVE/core/_OpenDriveElement.h"

/*
    <xs:simpleType name="e_countryCode_iso3166alpha2">
        <xs:restriction base="xs:string">
            <xs:pattern value="[A-Z]{2}"/>
        </xs:restriction>
    </xs:simpleType>
*/

namespace _NOD
{

#define _OD_STRING_ENUM_e_countryCode_iso3166alpha2(usingType) \
    _OD_STRING_ENUM_MAIN(usingType, e_countryCode_iso3166alpha2) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AD , _SC_AD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AE , _SC_AE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AF , _SC_AF) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AG , _SC_AG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AI , _SC_AI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AL , _SC_AL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AM , _SC_AM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AO , _SC_AO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AR , _SC_AR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AT , _SC_AT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AU , _SC_AU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, AZ , _SC_AZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BA , _SC_BA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BB , _SC_BB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BD , _SC_BD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BE , _SC_BE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BF , _SC_BF) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BG , _SC_BG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BH , _SC_BH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BI , _SC_BI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BJ , _SC_BJ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BM , _SC_BM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BN , _SC_BN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BO , _SC_BO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BR , _SC_BR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BS , _SC_BS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BT , _SC_BT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BW , _SC_BW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BY , _SC_BY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, BZ , _SC_BZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CA , _SC_CA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CD , _SC_CD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CF , _SC_CF) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CG , _SC_CG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CH , _SC_CH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CI , _SC_CI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CK , _SC_CK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CL , _SC_CL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CM , _SC_CM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CN , _SC_CN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CO , _SC_CO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CR , _SC_CR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CU , _SC_CU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CV , _SC_CV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CY , _SC_CY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, CZ , _SC_CZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, DE , _SC_DE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, DJ , _SC_DJ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, DK , _SC_DK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, DM , _SC_DM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, DO , _SC_DO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, DZ , _SC_DZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, EC , _SC_EC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, EE , _SC_EE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, EG , _SC_EG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, EH , _SC_EH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ER , _SC_ER) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ES , _SC_ES) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ET , _SC_ET) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, FI , _SC_FI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, FJ , _SC_FJ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, FK , _SC_FK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, FM , _SC_FM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, FO , _SC_FO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, FR , _SC_FR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GA , _SC_GA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GB , _SC_GB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GD , _SC_GD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GE , _SC_GE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GG , _SC_GG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GH , _SC_GH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GI , _SC_GI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GL , _SC_GL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GM , _SC_GM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GN , _SC_GN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GQ , _SC_GQ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GR , _SC_GR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GS , _SC_GS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GT , _SC_GT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GW , _SC_GW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, GY , _SC_GY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, HN , _SC_HN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, HR , _SC_HR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, HT , _SC_HT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, HU , _SC_HU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ID , _SC_ID) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IE , _SC_IE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IL , _SC_IL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IM , _SC_IM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IN , _SC_IN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IO , _SC_IO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IQ , _SC_IQ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IR , _SC_IR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IS , _SC_IS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, IT , _SC_IT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, JE , _SC_JE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, JM , _SC_JM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, JO , _SC_JO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, JP , _SC_JP) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KE , _SC_KE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KG , _SC_KG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KH , _SC_KH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KI , _SC_KI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KM , _SC_KM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KN , _SC_KN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KP , _SC_KP) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KR , _SC_KR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KW , _SC_KW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KY , _SC_KY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, KZ , _SC_KZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LA , _SC_LA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LB , _SC_LB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LC , _SC_LC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LI , _SC_LI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LK , _SC_LK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LR , _SC_LR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LS , _SC_LS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LT , _SC_LT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LU , _SC_LU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LV , _SC_LV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, LY , _SC_LY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MA , _SC_MA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MC , _SC_MC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MD , _SC_MD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ME , _SC_ME) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MG , _SC_MG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MH , _SC_MH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MK , _SC_MK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ML , _SC_ML) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MM , _SC_MM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MN , _SC_MN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MR , _SC_MR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MS , _SC_MS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MT , _SC_MT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MU , _SC_MU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MV , _SC_MV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MW , _SC_MW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MX , _SC_MX) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MY , _SC_MY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, MZ , _SC_MZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NA , _SC_NA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NE , _SC_NE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NG , _SC_NG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NI , _SC_NI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NL , _SC_NL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NO , _SC_NO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NP , _SC_NP) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NR , _SC_NR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NU , _SC_NU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, NZ , _SC_NZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, OM , _SC_OM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PA , _SC_PA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PE , _SC_PE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PG , _SC_PG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PH , _SC_PH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PK , _SC_PK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PL , _SC_PL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PN , _SC_PN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PT , _SC_PT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PW , _SC_PW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, PY , _SC_PY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, QA , _SC_QA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, RO , _SC_RO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, RS , _SC_RS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, RU , _SC_RU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, RW , _SC_RW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SA , _SC_SA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SB , _SC_SB) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SC , _SC_SC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SD , _SC_SD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SE , _SC_SE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SG , _SC_SG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SH , _SC_SH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SI , _SC_SI) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SK , _SC_SK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SL , _SC_SL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SM , _SC_SM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SN , _SC_SN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SO , _SC_SO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SR , _SC_SR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SS , _SC_SS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ST , _SC_ST) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SV , _SC_SV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SY , _SC_SY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, SZ , _SC_SZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TC , _SC_TC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TD , _SC_TD) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TG , _SC_TG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TH , _SC_TH) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TJ , _SC_TJ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TK , _SC_TK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TL , _SC_TL) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TM , _SC_TM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TN , _SC_TN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TO , _SC_TO) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TR , _SC_TR) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TT , _SC_TT) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TV , _SC_TV) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TW , _SC_TW) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, TZ , _SC_TZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, UA , _SC_UA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, UG , _SC_UG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, US , _SC_US) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, UY , _SC_UY) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, UZ , _SC_UZ) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, VA , _SC_VA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, VC , _SC_VC) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, VE , _SC_VE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, VG , _SC_VG) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, VN , _SC_VN) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, VU , _SC_VU) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, WS , _SC_WS) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, XK , _SC_XK) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, YE , _SC_YE) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ZA , _SC_ZA) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ZM , _SC_ZM) \
    _OD_STRING_ENUM_CONST(usingType, e_countryCode_iso3166alpha2, ZW , _SC_ZW) \
    EMPTY_COMMAND

struct e_countryCode_iso3166alpha2 : public _e_base
{
    _OD_STRING_ENUM_e_countryCode_iso3166alpha2(DECLARE)

public:
    e_countryCode_iso3166alpha2()
    {
        this->value = 0; // Default value
    }
};
}
