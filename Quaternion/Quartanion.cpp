
#include"Quartanion.h"
#include"math.h"

//�R���X�g���N�^
Quartanion::Quartanion(){}

//�f�X�g���N�^
Quartanion::~Quartanion(){}

//��]�N�H�[�^�j�I���̌v�Z
QuartanionElement Quartanion::CalculateRotateQuartanion(float angle, VEC3 axis)
{
	//�ŏI�I�ɕԂ��N�I�[�^�j�I��
	QuartanionElement quartanion;

	//�X�J���[��
	quartanion.q = cos(angle / 2);

	//�x�N�g����
	quartanion.V.x = axis.x * sin(angle / 2);
	quartanion.V.y = axis.y * sin(angle / 2);
	quartanion.V.z = axis.z * sin(angle / 2);

	return quartanion;
}

//������]�N�I�[�^�j�I���̌v�Z
QuartanionElement Quartanion::CalculateConjuRotateQuartanion(float angle, VEC3 axis) 
{
	//�ŏI�I�ɕԂ������N�I�[�^�j�I��
	QuartanionElement quartanion;

	//�X�J���[��
	quartanion.q = cos(angle / 2);

	//�x�N�g����
	quartanion.V.x = -axis.x * sin(angle / 2);
	quartanion.V.y = -axis.y * sin(angle / 2);
	quartanion.V.z = -axis.z * sin(angle / 2);

	return quartanion;
}


//�N�I�[�^�j�I����K�p
VEC3 Quartanion::AttatchQuartanion(VEC3 inputVec, QuartanionElement quartanion, QuartanionElement conjuQuartanion)
{
	//���̓x�N�g���̃N�I�[�^�j�I���ɕϊ�
	//�X�J���[��0, �x�N�g����inputVec
	QuartanionElement inputQuartanion = { 0,inputVec };

	//��]
	//quartanion * inputQuartanion * conjuQuartanion
	QuartanionElement tmp = MultQuartanion(quartanion, inputQuartanion);
	QuartanionElement tmp2= MultQuartanion(tmp, conjuQuartanion);

	return { tmp2.V.x,tmp2.V.y, tmp2.V.z };
}

//�N�I�[�^�j�I���̊|���Z
QuartanionElement MultQuartanion(QuartanionElement q1, QuartanionElement q2) 
{
	//�ŏI�I�ɕԂ��N�I�[�^�j�I��
	QuartanionElement quartanion;

	//�X�J���[��
	quartanion.q = q1.q * q2.q - Dot(q1.V, q2.V);

	//�x�N�g����
	VEC3 tmp1 = MultVec3(q1.q, q2.V);
	VEC3 tmp2 = MultVec3(q2.q, q1.V);
	VEC3 tmp3 = Cross(q1.V, q2.V);

	quartanion.V.x =tmp1.x+ tmp2.x + tmp3.x;
	quartanion.V.y =tmp1.y+ tmp2.y + tmp3.y;
	quartanion.V.z =tmp1.z+ tmp2.z + tmp3.z;

	return quartanion;
}

//����
double Dot(VEC3 v1, VEC3 v2) 
{
	return v1.x* v2.x + v1.y * v2.y + v1.z * v2.z;
}

//�O��
VEC3 Cross(VEC3 v1, VEC3 v2)
{
	//�ŏI�I�ɕԂ��x�N�g��
	VEC3 vec3;

	//�O�όv�Z
	vec3.x = v1.y * v2.z - v1.z * v2.y;
	vec3.y = v1.z * v2.x - v1.x * v2.z;
	vec3.z = v1.x * v2.y - v1.y * v2.x;

	return vec3;
}

VEC3 MultVec3(double d, VEC3 v)
{
	return {d * v.x, d * v.y, d * v.z};
}