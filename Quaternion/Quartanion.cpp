
#include"Quartanion.h"
#include"math.h"

//コンストラクタ
Quartanion::Quartanion(){}

//デストラクタ
Quartanion::~Quartanion(){}

//回転クォータニオンの計算
QuartanionElement Quartanion::CalculateRotateQuartanion(float angle, VEC3 axis)
{
	//最終的に返すクオータニオン
	QuartanionElement quartanion;

	//スカラー部
	quartanion.q = cos(angle / 2);

	//ベクトル部
	quartanion.V.x = axis.x * sin(angle / 2);
	quartanion.V.y = axis.y * sin(angle / 2);
	quartanion.V.z = axis.z * sin(angle / 2);

	return quartanion;
}

//共役回転クオータニオンの計算
QuartanionElement Quartanion::CalculateConjuRotateQuartanion(float angle, VEC3 axis) 
{
	//最終的に返す共役クオータニオン
	QuartanionElement quartanion;

	//スカラー部
	quartanion.q = cos(angle / 2);

	//ベクトル部
	quartanion.V.x = -axis.x * sin(angle / 2);
	quartanion.V.y = -axis.y * sin(angle / 2);
	quartanion.V.z = -axis.z * sin(angle / 2);

	return quartanion;
}


//クオータニオンを適用
VEC3 Quartanion::AttatchQuartanion(VEC3 inputVec, QuartanionElement quartanion, QuartanionElement conjuQuartanion)
{
	//入力ベクトルのクオータニオンに変換
	//スカラー部0, ベクトル部inputVec
	QuartanionElement inputQuartanion = { 0,inputVec };

	//回転
	//quartanion * inputQuartanion * conjuQuartanion
	QuartanionElement tmp = MultQuartanion(quartanion, inputQuartanion);
	QuartanionElement tmp2= MultQuartanion(tmp, conjuQuartanion);

	return { tmp2.V.x,tmp2.V.y, tmp2.V.z };
}

//クオータニオンの掛け算
QuartanionElement MultQuartanion(QuartanionElement q1, QuartanionElement q2) 
{
	//最終的に返すクオータニオン
	QuartanionElement quartanion;

	//スカラー部
	quartanion.q = q1.q * q2.q - Dot(q1.V, q2.V);

	//ベクトル部
	VEC3 tmp1 = MultVec3(q1.q, q2.V);
	VEC3 tmp2 = MultVec3(q2.q, q1.V);
	VEC3 tmp3 = Cross(q1.V, q2.V);

	quartanion.V.x =tmp1.x+ tmp2.x + tmp3.x;
	quartanion.V.y =tmp1.y+ tmp2.y + tmp3.y;
	quartanion.V.z =tmp1.z+ tmp2.z + tmp3.z;

	return quartanion;
}

//内積
double Dot(VEC3 v1, VEC3 v2) 
{
	return v1.x* v2.x + v1.y * v2.y + v1.z * v2.z;
}

//外積
VEC3 Cross(VEC3 v1, VEC3 v2)
{
	//最終的に返すベクトル
	VEC3 vec3;

	//外積計算
	vec3.x = v1.y * v2.z - v1.z * v2.y;
	vec3.y = v1.z * v2.x - v1.x * v2.z;
	vec3.z = v1.x * v2.y - v1.y * v2.x;

	return vec3;
}

VEC3 MultVec3(double d, VEC3 v)
{
	return {d * v.x, d * v.y, d * v.z};
}