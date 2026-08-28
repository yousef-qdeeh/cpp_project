#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;
namespace activationAnd2FactorActions{
int generateRandomOtp(int from , int to){
    int opt=(rand()%(to-from+1)+from);
    return opt;
}
/*مستقبلا سيتم وضع دوال تقوم ب 
تخزين ال 
otp  
في ملف نصي خارجي و بطلب منك ادخالو 
ولو ل مليون سنة طول ما انت مش مدخل صح ح اضل اطلب منك 
تدخل ال 
otp 
الصج
*/
int read_Otp_Activation_Key(){
    cout<<" requrired Security Action \n\n";
    int number=0;
    cout<<"Enter temporary ACTIVATION CODE (OTP)  : ";
    cin>>number;
    return number;
}

bool isPassedFromSecurityAction(){//this like capitcha in web sites but in console application not in websites 
    cout<<"\n\nrequired security Action ! \n\n";
    int *OTP_CODE=new int(generateRandomOtp(1111,9999));
    cout<<"Activation key is : " <<*OTP_CODE<<endl;
    int userInput=read_Otp_Activation_Key();
    if(*OTP_CODE==userInput){
        delete OTP_CODE;  
         OTP_CODE = nullptr;  
        return true;
    }

    delete OTP_CODE; 
     OTP_CODE = nullptr;
    return false;
}
}

