

// 全局变量
// bss 段
g_peak_save; //10个字节
g_step_save; //10个字节
g_step_freq_save; // 20个字节
// extern 
extern g_data_x;
extern g_data_y;
extern g_data_z;
extern g_data_compose;
extern g_data_timestamp; // 240个字节

dword_434;
dword_438;
dword_43C;
dword_440;

//data段
g_peak_save_index;
g_data_index;
g_isfemale;
s_has_init;
g_height_cm;
g_weight_kg;
g_age;
s_step_error_desc
s_mode
s_one_step_calory

/*外部函数*/
IMPORT __aeabi_idivmod  
IMPORT __aeabi_ldivmod  
IMPORT __aeabi_lmul     
IMPORT generate_event   
IMPORT get_distance_data
                        
IMPORT get_step_data    
IMPORT step_count_init  
IMPORT Lib$$Request$$armlib, WEAK


/*本地函数*/
signed int  init_distance_algorithm(int data_fs, __int16 stature, __int16 weight, __int16 age, char man_or_woman);
signed int distance_algorithm_finalize();
int distance_algorithm_error_desc();
signed int  distance_algorithm_accelerate_data_in(__int16 a1, int a2, int a3, int a4, int a5, int a6);


signed int  init_distance_algorithm(int data_fs, __int16 stature, __int16 weight, __int16 age, char man_or_woman)
{
  unsigned int v5; // r5
  signed int result; // r0
  const char *v7; // r1

  v5 = data_fs - 15;
  result = -1;
  if ( v5 >= 21 )
  {
    v7 = "distance algorithm does not support the input sample rate";
ret_1:
    s_step_error_desc = (int)v7;
    return result;
  }
  if ( s_has_init )
  {
    v7 = "distance algorithm has already been initialized";
    goto ret_1;
  }
  g_height_cm = stature;
  g_weight_kg = weight;
  g_age = age;
  g_isfemale = man_or_woman;
  g_data_index = 0;
  g_peak_save_index = 0;
  step_count_init();
  s_has_init = 1;
  return 0;
}


signed int distance_algorithm_finalize()
{
  signed int result; // r0

  if ( s_has_init )
  {
    s_has_init = 0;
    result = 0;
  }
  else
  {
    s_step_error_desc = (int)"distance algorithm has not been initialized yet";
    result = -1;
  }
  return result;
}


int distance_algorithm_error_desc()
{
  return s_step_error_desc;
}


signed int  distance_algorithm_accelerate_data_in(__int16 a1, int a2, int a3, int a4, int a5, int a6)
{
  const char *v6; // r0
  __int16 v7; // r6
  int v8; // r0
  int v9; // r5
  _DWORD *v10; // r3
  __int16 v11; // r0
  int v12; // r6
  __int64 v13; // r0
  signed __int64 v14; // r2
  int v15; // r7
  int v17; // r0
  signed int v18; // r0
  int v19; // r1
  int v20; // r3
  int *v21; // r5
  int v22; // r3
  int v23; // r5
  _DWORD *v24; // r2
  int v25; // [sp+0h] [bp-20h]
  int v26; // [sp+4h] [bp-1Ch]
  int v27; // [sp+8h] [bp-18h]

  v25 = a2;
  v26 = a3;
  v27 = a4;
  if ( s_has_init != 1 )
  {
    v6 = "distance algorithm has not been initialized yet";
LABEL_6:
    s_step_error_desc = (int)v6;
    return -1;
  }
  LOWORD(v25) = 0;
  v7 = a1;
  v8 = g_data_index;
  v9 = g_data_index;
  g_data_x[v9] = v7;
  g_data_y[v9] = a2;
  g_data_z[v9] = a3;
  g_data_compose[v9] = a4;
  v10 = (_DWORD *)((char *)&g_data_timestamp + 8 * v8);
  *v10 = a5;
  v10[1] = a6;
  g_data_index = (v8 + 1) % 30;
  if ( !g_data_index )
  {
    v11 = get_step_data(&v25, &s_mode);
    v26 = (signed __int16)v25;
    v12 = (signed __int16)(v11 + v25);
    v13 = (signed __int16)(v11 + v25) * s_one_step_calory;
    v14 = v13 % 10000;
    v15 = v13 / 10000;
    if ( v12 < 0 )
    {
      v6 = "failed to call function get_step_data";
      goto LABEL_6;
    }
    if ( v12 > 0 )
    {
      v17 = get_distance_data(v26, 3, v14, HIDWORD(v14));
      dword_434 = v12;
      s_distance_event = 2;
      dword_438 = v17;
      dword_440 = v15;
      dword_43C = s_mode;
      generate_event();
    }
    v18 = 24;
    do
    {
      v19 = g_data_index;
      v20 = g_data_index;
      g_data_x[v20] = g_data_x[v18];
      g_data_y[v20] = g_data_y[v18];
      g_data_z[v20] = g_data_z[v18];
      g_data_compose[v20] = g_data_compose[v18];
      v21 = (int *)((char *)&g_data_timestamp + 8 * v18);
      v22 = *v21;
      v23 = v21[1];
      v24 = (_DWORD *)((char *)&g_data_timestamp + 8 * v19);
      *v24 = v22;
      v24[1] = v23;
      v18 = (char)(v18 + 1);
      g_data_index = v19 + 1;
    }
    while ( v18 < 30 );
  }
  return 0;
}

