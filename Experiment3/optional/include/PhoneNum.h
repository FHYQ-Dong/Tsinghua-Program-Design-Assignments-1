#ifndef _PHONE_NUM_H_
#define _PHONE_NUM_H_

typedef long long ll;
typedef struct PhoneNumObj PhoneNumObj;

struct PhoneNumObj {
    char Name[100];
    char PhoneNum_1to2;
    int PhoneNum_3to11;
    ll (*oPhoneNum)(struct PhoneNumObj *this);
    void (*iPhoneNum)(ll phn, struct PhoneNumObj *this);
};

ll oPhoneNum(struct PhoneNumObj *this);

void iPhoneNum(ll phn, struct PhoneNumObj *this);

#endif