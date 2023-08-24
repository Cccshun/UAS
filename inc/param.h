#ifndef _PARAM_H_
#define _PARAM_H_

// 场地大小
const double kLength = 20;
const double kWidth = 9;
// 每个格子大小0.1*0.1
const double kCellDistance = 1;

// 矩阵维度n×m
const int kN = kLength / kCellDistance;
const int kM = kWidth / kCellDistance;

// 有效传播距离
const double kDISTANCE = 4;
const int kACTIVEDRANGE = kDISTANCE / kCellDistance;

const int kSEED_SIZE = 5;
const int kPOP_SIZE = 20;
const int kMAX_GENS = 100;
const double kCROSSOVER = 0.5;
const double kMUTATE = 0.1;
const double kLOCAL_SEARCH = 0.2;

#endif