typedef long long ll;

struct PhoneNumObj{
    char Name[100];
    char PhoneNum_1to2;
    int PhoneNum_3to11;
    ll (*oPhoneNum)(struct PhoneNumObj *this);
    void (*iPhoneNum)(ll phn, struct PhoneNumObj *this);
};

ll oPhoneNum(struct PhoneNumObj *this) { // output PhoneNum
    return (int)(this->PhoneNum_1to2) * (ll)(1e9) + this->PhoneNum_3to11;
}

void iPhoneNum(ll phn, struct PhoneNumObj *this) { // input PhoneNum
    this->PhoneNum_1to2 = phn / (ll)(1e9);
    this->PhoneNum_3to11 = phn % (ll)(1e9);
    return;
}