#include<winsock2.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#pragma comment(lib,"ws2_32.lib")
#define BUFFER_SIZE 1024

#define  uint8		UINT8
#define  uint16		UINT16
#define  uint32		UINT32
#define  float32	float


namespace wsc{

	namespace www{
		uint8 origin;
	}
	
}


typedef uint32 Dt_ARRAY_UINT64_1_0[2];


typedef struct
{
	uint16 Counter;
	uint8 FrameID;
	uint8 PaddingGap8_1;
	Dt_ARRAY_UINT64_1_0 TimeStamp;
} Dt_RECORD_HEADER;      //12 bytes

typedef struct
{
	uint8 OBJ_Zero_byte;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	uint32 Reserved_1;
	uint32 OBJ_Header_CRC;
	uint8 OBJ_Protocol_Version;
	uint8 OBJ_Sync_ID;         //14 bytes
	uint8 OBJ_VRU_Count;
	uint8 OBJ_VD_Count;
	uint8 OBJ_General_OBJ_Count;
	uint8 Reserved_2;
	uint8 OBJ_Animal_Count;
	uint8 OBJ_VD_NIV_Left;
	uint8 OBJ_VD_NIV_Right;
	uint8 OBJ_VD_CIPV_ID;
	uint8 OBJ_VD_CIPV_Lost;
	uint8 OBJ_VD_Allow_Acc;
	boolean OBJ_Is_Blocked_Left;
	boolean OBJ_Is_Blocked_Right;
	uint16 PaddingGap16_3;
	uint32 Reserved_3;
} Dt_RECORD_Objects_Header;


typedef struct
{
	uint32 OBJ_CRC;
	uint8 OBJ_ID;
	uint8 PaddingGap8_1;
	uint16 PaddingGap16_2;
	float32 OBJ_Existence_Probability;
	uint16 OBJ_Fusion_Source;
	uint8 OBJ_Triggered_SDM;
	uint8 OBJ_Motion_Category;
	float32 OBJ_Buffer_C0;
	uint16 OBJ_Object_Age;
	uint8 OBJ_Measuring_Status;
	uint8 OBJ_Object_Class;
	boolean Reserved_4;
	uint8 PaddingGap8_3;
	uint16 PaddingGap16_4;
	float32 OBJ_Class_Probability;
	float32 OBJ_Buffer_C1;
	float32 OBJ_Buffer_C2;
	float32 OBJ_Buffer_C3;
	uint8 OBJ_Camera_Source;
	uint8 OBJ_Motion_Status;
	uint8 OBJ_Motion_Orientation;
	boolean OBJ_Has_Cut_Lane;
	boolean OBJ_Has_Cut_Path;
	boolean OBJ_Brake_Light;
	boolean OBJ_Turn_Indicator_Right;
	boolean OBJ_Turn_Indicator_Left;
	boolean OBJ_Light_Indicator_Validity;
	boolean OBJ_Right_Out_Of_Image;
	boolean OBJ_Left_Out_Of_Image;
	boolean OBJ_Right_Out_Of_Image_V;
	boolean OBJ_Left_Out_Of_Image_V;
	boolean OBJ_Top_Out_Of_Image;
	boolean OBJ_Bottom_Out_Of_Image;
	boolean OBJ_Top_Out_Of_Image_V;
	boolean OBJ_Bottom_Out_Of_Image_V;
	uint8 OBJ_Lane_Assignment;
	boolean OBJ_Lane_Assignment_V;
	uint8 OBJ_Age_Seconds;
	boolean OBJ_Age_Seconds_V;
	uint8 PaddingGap8_5;
	uint16 PaddingGap16_6;
	float32 OBJ_Width;
	boolean OBJ_Width_V;
	uint8 PaddingGap8_7;
	uint16 PaddingGap16_8;
	float32 OBJ_Width_STD;
	boolean OBJ_Width_STD_V;
	uint8 PaddingGap8_9;
	uint16 PaddingGap16_10;
	float32 OBJ_Length;
	boolean OBJ_Length_V;
	uint8 Reserved_5;
	uint16 PaddingGap16_11;
	float32 OBJ_Length_STD;
	boolean OBJ_Length_STD_V;
	uint8 PaddingGap8_12;
	uint16 PaddingGap16_13;
	float32 OBJ_Height;
	boolean OBJ_Height_V;
	uint8 PaddingGap8_14;
	uint16 PaddingGap16_15;
	float32 OBJ_Height_STD;
	boolean OBJ_Height_STD_V;
	uint8 Reserved_6;
	uint16 PaddingGap16_16;
	float32 OBJ_Abs_Long_Velocity;
	boolean OBJ_Abs_Long_Velocity_V;
	uint8 PaddingGap8_17;
	uint16 PaddingGap16_18;
	float32 OBJ_Abs_Long_Velocity_STD;
	boolean OBJ_Abs_Long_Vel_STD_V;
	uint8 Reserved_7;
	uint16 PaddingGap16_19;
	float32 OBJ_Abs_Lat_Velocity;
	boolean OBJ_Abs_Lat_Velocity_V;
	uint8 PaddingGap8_20;
	uint16 PaddingGap16_21;
	float32 OBJ_Abs_Lat_Velocity_STD;
	boolean OBJ_Abs_Lat_Vel_STD_V;
	uint8 PaddingGap8_22;
	uint16 PaddingGap16_23;
	float32 OBJ_Abs_Long_Acc;
	boolean OBJ_Abs_Long_Acc_V;
	uint8 PaddingGap8_24;
	uint16 PaddingGap16_25;
	float32 OBJ_Abs_Long_Acc_STD;
	boolean OBJ_Abs_Long_Acc_STD_V;
	uint8 PaddingGap8_26;
	uint16 PaddingGap16_27;
	float32 OBJ_Abs_Lat_Acc;
	boolean OBJ_Abs_Lat_Acc_V;
	uint8 PaddingGap8_28;
	uint16 PaddingGap16_29;
	float32 OBJ_Abs_Lat_Acc_STD;
	boolean OBJ_Abs_Lat_Acc_STD_V;
	uint8 Reserved_8;
	uint16 PaddingGap16_30;
	float32 OBJ_Abs_Acceleration;
	boolean OBJ_Abs_Acceleration_V;
	uint8 PaddingGap8_31;
	uint16 PaddingGap16_32;
	float32 OBJ_Abs_Acc_STD;
	boolean OBJ_Abs_Acc_STD_V;
	uint8 PaddingGap8_33;
	uint16 PaddingGap16_34;
	float32 OBJ_Inv_TTC;
	boolean OBJ_Inv_TTC_V;
	boolean Reserved_9;
	uint16 PaddingGap16_35;
	float32 OBJ_Inv_TTC_STD;
	boolean OBJ_Inv_TTC_STD_V;
	uint8 PaddingGap8_36;
	uint16 PaddingGap16_37;
	float32 OBJ_Relative_Long_Acc;
	boolean OBJ_Relative_Long_Acc_V;
	uint8 PaddingGap8_38;
	uint16 PaddingGap16_39;
	float32 OBJ_Relative_Long_Acc_STD;
	boolean OBJ_Rel_Long_Acc_STD_V;
	boolean Reserved_10;
	uint16 PaddingGap16_40;
	float32 OBJ_Relative_Long_Velocity;
	boolean OBJ_Relative_Long_Velocity_V;
	uint8 PaddingGap8_41;
	uint16 PaddingGap16_42;
	float32 OBJ_Relative_Long_Vel_STD;
	boolean OBJ_Rel_Long_Vel_STD_V;
	uint8 Reserved_11;
	uint16 PaddingGap16_43;
	float32 OBJ_Relative_Lat_Velocity;
	boolean OBJ_Relative_Lat_Velocity_V;
	uint8 PaddingGap8_44;
	uint16 PaddingGap16_45;
	float32 OBJ_Relative_Lat_Velocity_STD;
	boolean OBJ_Rel_Lat_Vel_STD_V;
	uint8 PaddingGap8_46;
	uint16 Reserved_12;
	float32 OBJ_Long_Distance;
	boolean OBJ_Long_Distance_V;
	uint8 PaddingGap8_47;
	uint16 PaddingGap16_48;
	float32 OBJ_Long_Distance_STD;
	boolean OBJ_Long_Distance_STD_V;
	uint8 Reserved_13;
	uint16 PaddingGap16_49;
	float32 OBJ_Lat_Distance;
	boolean OBJ_Lat_Distance_V;
	uint8 PaddingGap8_50;
	uint16 PaddingGap16_51;
	float32 OBJ_Lat_Distance_STD;
	boolean OBJ_Lat_Distance_STD_V;
	uint8 Reserved_14;
	uint16 PaddingGap16_52;
	float32 OBJ_Absolute_Speed;
	boolean OBJ_Absolute_Speed_V;
	uint8 PaddingGap8_53;
	uint16 PaddingGap16_54;
	float32 OBJ_Absolute_Speed_STD;
	boolean OBJ_Absolute_Speed_STD_V;
	uint8 Reserved_15;
	uint16 PaddingGap16_55;
	float32 OBJ_Heading;
	boolean OBJ_Heading_V;
	uint8 PaddingGap8_56;
	uint16 PaddingGap16_57;
	float32 OBJ_Heading_STD;
	boolean OBJ_Heading_STD_V;
	uint8 PaddingGap8_58;
	uint16 PaddingGap16_59;
	float32 OBJ_Angle_Rate_STD;
	boolean OBJ_Angle_Rate_STD_V;
	uint8 PaddingGap8_60;
	uint16 PaddingGap16_61;
	float32 OBJ_Angle_Rate;
	boolean OBJ_Angle_Rate_V;
	uint8 PaddingGap8_62;
	uint16 PaddingGap16_63;
	float32 OBJ_Angle_Right;
	boolean OBJ_Angle_Right_V;
	uint8 Reserved_16;
	uint16 PaddingGap16_64;
	float32 OBJ_Angle_Right_STD;
	boolean OBJ_Angle_Right_STD_V;
	uint8 PaddingGap8_65;
	uint16 PaddingGap16_66;
	float32 OBJ_Angle_Left;
	boolean OBJ_Angle_Left_V;
	uint8 Reserved_17;
	uint16 PaddingGap16_67;
	float32 OBJ_Angle_Left_STD;
	boolean OBJ_Angle_Left_STD_V;
	uint8 PaddingGap8_68;
	uint16 PaddingGap16_69;
	float32 OBJ_Angle_Side;
	boolean OBJ_Angle_Side_V;
	uint8 Reserved_18;
	uint16 PaddingGap16_70;
	float32 OBJ_Angle_Side_STD;
	boolean OBJ_Angle_Side_STD_V;
	boolean OBJ_Angle_Mid_V;
	uint16 PaddingGap16_71;
	float32 OBJ_Angle_Mid;
	uint8 Reserved_19;
	uint8 PaddingGap8_72;
	uint16 PaddingGap16_73;
	float32 OBJ_Angle_Mid_STD;
	boolean OBJ_Angle_Mid_STD_V;
	boolean OBJ_Angle_Bottom_V;
	uint16 PaddingGap16_74;
	float32 OBJ_Angle_Bottom;
	uint8 Reserved_20;
	uint8 PaddingGap8_75;
	uint16 PaddingGap16_76;
	float32 OBJ_Angle_Bottom_STD;
	boolean OBJ_Angle_Bottom_STD_V;
	boolean OBJ_Visibility_Side_V;
	uint8 OBJ_Visibility_Side;
	boolean OBJ_Is_In_Drivable_Area;
	boolean OBJ_Is_In_Drivable_Area_V;
	boolean OBJ_Is_VeryClose_V;
	boolean OBJ_Is_VeryClose;
	uint8 OBJ_Buffer_C4;
	uint8 OBJ_Buffer_C5;
	uint8 OBJ_Buffer_C6;
	uint8 OBJ_Buffer_C7;
	uint8 Reserved_21;
	float32 OBJ_Buffer_C8;
	float32 OBJ_Buffer_C9;
	uint16 Reserved_22;
	uint16 PaddingGap16_77;
} Dt_RECORD_Objects;


typedef Dt_RECORD_Objects Dt_ARRAY_2_Object[2];

typedef struct
{
	Dt_RECORD_HEADER			stHeader;
	Dt_RECORD_Objects_Header	stObjects_Header;
	Dt_ARRAY_2_Object			gstObjects_Element;
} Dt_RECORD_MeObjects_E_x;


class test
{
public:
	void Set(int &pInstance, int pFun);

private:
	int* m_pInstance;
};

void test::Set(int &pInstance, int pFun)
{
	m_pInstance = &pInstance;
	cout << *m_pInstance << endl;
}
