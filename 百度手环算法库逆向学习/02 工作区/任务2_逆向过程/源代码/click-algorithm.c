

/*用到的全局变量*/
// data 段
s_has_init;
s_data_cur_idx;
s_data_idx;
s_data_cur_idx_time;
s_data_idx_time;
int (__fastcall *s_click_callback)(_DWORD, _DWORD); //s_click_callback DCD init_click_algorithm
s_error_desc;
s_SVM_value;
s_click_event;
dword_73C;

// bs 段
s_data_x; //memory 占据60字节
s_data_y;
s_data_z;
s_data_compose;
s_data_timestamp;
//const_data
k_SVM_threshold //k_SVM_threshold DCD 600000
k_SVM_bias      //k_SVM_bias      DCD 4291776507  0xFFCF4FFB
k_SVM_alpha     //占240个字节的数组


//s_click_callback_data DCD 0 

/* 函数表*/
signed int  init_click_algorithm(int data_fs);
int click_algorithm_finalize();
signed int  register_click_algorithm_callback(int (*a1)(), int a2);
int click_algorithm_error_desc();
signed int  generate_click_event(int a1);
signed int  compute_peak_feature_core(int a1, int a2, char *a3);
signed int  click_algorithm_accelerate_data_in(__int16 a1, int a2, int a3, int a4, int a5, int a6);
int  get_idx(int a1, int a2);
signed int  compute_peak_feature(int a1, int a2, int a3, int a4);
signed int  detect_peak(_BYTE *a1);
int  _ARM_common_ll_mulss(int a1, int a2);




signed int  init_click_algorithm(int data_fs)
{
  const char *v1; // r0
  signed int v3; // r0
  signed int v4; // r4

  if ( s_has_init == 1 )
  {
    v1 = "click algorithm has been initialized";
    goto LABEL_4;
  }
  if ( (unsigned int)(data_fs - 85) >= 0x24 )
  {
    v1 = "click algorithm only supports 85~120HZ sample";
LABEL_4:
    s_error_desc = (int)v1;
    return -1;
  }
  v3 = 0;
  do
  {
    v4 = v3;
    v3 = (char)(v3 + 1);
    s_data_compose[v4] = 0x7FFF;
  }
  while ( v3 < 30 );
  s_data_cur_idx = 0;
  s_data_idx = 16;
  s_data_cur_idx_time = 0;
  s_data_idx_time = 1;
  s_has_init = 1;
  return 0;
}


int click_algorithm_finalize()
{
  int result; // r0

  result = 0;
  s_has_init = 0;
  return result;
}

signed int  register_click_algorithm_callback(int (*a1)(), int a2)
{
  if ( !a1 )
    return -1;
  s_click_callback_data = a2;
  s_click_callback = (int ( *)(_DWORD, _DWORD))a1;
  return 0;
}


int click_algorithm_error_desc()
{
  return s_error_desc;
}

signed int  generate_click_event(int a1)
{
  if ( !s_click_callback )
    return -1;
  s_click_callback(a1, s_click_callback_data);
  return 0;
}

signed int  compute_peak_feature_core(int a1, int a2, char *a3)
{
  char *v3; // r5
  int v4; // r6
  __int64 v5; // r0
  signed int v6; // r4
  signed int v8; // r7
  int v9; // r1
  int v10; // r0
  __int64 v11; // r0
  int v12; // r7
  int v13; // r0
  __int64 v14; // r0
  int v15; // [sp+0h] [bp-30h]
  __int16 v16; // [sp+0h] [bp-30h]
  int v17; // [sp+4h] [bp-2Ch]
  int v18; // [sp+Ch] [bp-24h]
  int v19; // [sp+14h] [bp-1Ch]

  v19 = a2;
  v3 = a3;
  v4 = a1;
  if ( !a1 || !a3 )
    return -1;
  LODWORD(v5) = _ARM_common_ll_mulss(k_SVM_alpha[*a3], *(signed __int16 *)(a1 + 2 * ((a2 + 30) % 30)));
  v6 = 1;
  s_SVM_value += v5;
  do
  {
    if ( *v3 + v6 + 1 >= 60 )
    {
      s_error_desc = (int)"the number of features in click algorithm is not right";
      return -1;
    }
    v15 = 0;
    v8 = (char)-(char)v6;
    while ( v8 <= v6 )
    {
      v9 = (v19 + v8 + 30) % 30;
      v8 = (char)(v8 + 1);
      v15 += *(signed __int16 *)(v4 + 2 * (char)v9);
    }
    v17 = 2 * v6;
    v10 = v15 / (2 * v6 + 1);
    v16 = v15 / (2 * v6 + 1);
    LODWORD(v11) = _ARM_common_ll_mulss(k_SVM_alpha[*v3 + v6], v10);
    s_SVM_value += v11;
    v18 = 0;
    v12 = (char)-(char)v6;
    while ( v12 <= v6 )
    {
      v13 = (signed __int16)(*(_WORD *)(v4 + 2 * get_idx(v19, v12)) - v16);
      if ( v13 <= 0 )
        v13 = -v13;
      v12 = (char)(v12 + 1);
      v18 += (signed __int16)v13;
    }
    LODWORD(v14) = _ARM_common_ll_mulss(k_SVM_alpha[*v3 + 1 + v6], v18);
    v6 = (char)(v6 + 2);
    s_SVM_value += v14 / (v17 + 1);
  }
  while ( v6 <= 14 );
  *v3 += 15;
  return 0;
}

signed int  click_algorithm_accelerate_data_in(__int16 a1, int a2, int a3, int a4, int a5, int a6)
{
  __int16 v6; // r7
  int v7; // r0
  unsigned int v8; // r6
  int v9; // r6
  int *v10; // r3
  int v11; // r1
  int v12; // r2
  int v13; // r3
  signed int result; // r0
  const char *v15; // r0
  int v16; // r1
  int v17; // r0
  int v18; // [sp+0h] [bp-20h]
  int v19; // [sp+4h] [bp-1Ch]
  int v20; // [sp+8h] [bp-18h]

  v18 = a2;
  v19 = a3;
  v20 = a4;
  if ( !s_has_init )
  {
    v15 = "click algorithm has not been initialized";
LABEL_10:
    s_error_desc = (int)v15;
    return -1;
  }
  v6 = a1;
  v7 = s_data_cur_idx;
  v8 = 2 * s_data_cur_idx;
  *(_WORD *)((char *)&s_data_x + v8) = v6;
  *(_WORD *)((char *)&s_data_y + v8) = a2;
  *(_WORD *)((char *)&s_data_z + v8) = a3;
  s_data_compose[v8 / 2] = a4;
  v9 = s_data_cur_idx_time;
  v10 = (int *)((char *)&s_data_timestamp + 8 * s_data_cur_idx_time);
  *v10 = a5;
  v10[1] = a6;
  s_data_cur_idx = (v7 + 31) % 30;
  v11 = (s_data_idx + 31) % 30;
  s_data_idx = v11;
  s_data_cur_idx_time = (v9 + 1) % 15;
  s_data_idx_time = (s_data_idx_time + 1) % 15;
  LOBYTE(v18) = 0;
  LOBYTE(v19) = 0;
  if ( s_data_compose[(char)v11] < 1464 )
    return 0;
  if ( detect_peak(&v18) )
    return -1;
  result = (unsigned __int8)v18;
  if ( (_BYTE)v18 )
  {
    s_SVM_value = -3190789LL;
    if ( compute_peak_feature(-3190789, -1, v12, v13) )
    {
      v15 = "click algorithm fails to compute peak feature";
      goto LABEL_10;
    }
    if ( s_SVM_value < 600000 )
      LOBYTE(v19) = -1;
    else
      LOBYTE(v19) = 1;
    if ( (unsigned __int8)v19 == 1 )
    {
      v16 = 8 * s_data_idx_time;
      v17 = *(_DWORD *)((char *)&s_data_timestamp + v16 + 4);
      s_click_event = *(_DWORD *)((char *)&s_data_timestamp + v16);
      dword_73C = v17;
      generate_click_event((int)&s_click_event);
    }
    return 0;
  }
  return result;
}

int  get_idx(int a1, int a2)
{
  return (a1 + a2 + 30) % 30;
}

signed int  compute_peak_feature(int a1, int a2, int a3, int a4)
{
  int v5; // [sp+0h] [bp-10h]

  v5 = a4;
  LOBYTE(v5) = 0;
  if ( compute_peak_feature_core((int)&s_data_x, s_data_idx, (char *)&v5)
    || compute_peak_feature_core((int)&s_data_y, s_data_idx, (char *)&v5)
    || compute_peak_feature_core((int)&s_data_z, s_data_idx, (char *)&v5)
    || compute_peak_feature_core((int)s_data_compose, s_data_idx, (char *)&v5) )
  {
    return -1;
  }
  if ( (unsigned __int8)v5 != 60 )
  {
    s_error_desc = (int)"the number of features is not right in click algorithm";
    return -1;
  }
  return 0;
}


signed int  detect_peak(_BYTE *a1)
{
  _BYTE *v1; // r7
  int v2; // r4

  v1 = a1;
  if ( !a1 )
    return -1;
  *a1 = 1;
  v2 = 1;
  while ( s_data_compose[get_idx(s_data_idx, (char)-(char)v2)] < s_data_compose[s_data_idx]
       && s_data_compose[get_idx(s_data_idx, v2)] <= s_data_compose[s_data_idx] )
  {
    v2 = (char)(v2 + 1);
    if ( v2 > 10 )
      return 0;
  }
  *v1 = 0;
  return 0;
}

int  _ARM_common_ll_mulss(int a1, int a2)
{
  return      (unsigned __int16)a1 * (unsigned __int16)a2
            + ((signed __int64)((a1 >> 16) * (unsigned __int16)a2) << 16)
            + ((signed __int64)((unsigned __int16)a1 * (a2 >> 16)) << 16);
}
