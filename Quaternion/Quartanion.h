
#ifndef _QUARTANION
#define _QUARTANION

#include "VEC3.h"
#include "QuartanionElement.h"

class Quartanion {
public:
	Quartanion();

	~Quartanion();

	/**
	 * @brief 任意軸で任意角回転を表すクオータニオン
	 * @param[in]	angle	回転角(単位:radian)
	 * @param[in]	axis	回転軸(正規化済み)
	 * @return		回転を表すクオータニオン
	 */
	QuartanionElement CalculateRotateQuartanion(float angle, VEC3 axis);

	/**
	 * @brief 任意軸で任意角回転を表す共役クオータニオン
	 * @param[in]	angle	回転角(単位:radian)
	 * @param[in]	axis	回転軸(正規化済み)
	 * @return		回転を表す共役クオータニオン
	 */
	QuartanionElement CalculateConjuRotateQuartanion(float angle, VEC3 axis);

	/**
	 * @brief 任意のベクトルを、クオータニオンで座標変換
	 * @param[in]	inputVec	変換したいベクトル
	 * @param[in]	quartanion	クオータニオン
	 * @param[in]	quartanion	共役クオータニオン
	 * @return		変換済みクオータニオン
	 */
	VEC3 AttatchQuartanion(VEC3 inputVec, QuartanionElement quartanion, QuartanionElement conjuQuartanion);
};

/**
* @brief 任意のベクトルを、クオータニオンの掛け算
* @param[in]	q1	クオータニオン1
* @param[in]	q2	クオータニオン2
* @return	クオータニオンの掛け算結果
*/
QuartanionElement MultQuartanion(QuartanionElement q1, QuartanionElement q2);

/**
* @brief 内積
* @param[in]	v1	ベクトル1
* @param[in]	v2	ベクトル2
* @return	内積結果
*/
double Dot(VEC3 v1, VEC3 v2);

/**
* @brief 外積
* @param[in]	v1	ベクトル1
* @param[in]	v2	ベクトル2
* @return	外積結果
*/
VEC3 Cross(VEC3 v1, VEC3 v2);

/**
* @brief スカラーとベクトルの積
* @param[in]	d	スカラー
* @param[in]	v	ベクトル
* @return	スカラーとベクトルの積
*/
VEC3 MultVec3(double d, VEC3 v);

#endif // _QUARTANION
