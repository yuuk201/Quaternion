
#ifndef _QUARTANION
#define _QUARTANION

#include "VEC3.h"
#include "QuartanionElement.h"

class Quartanion {
public:
	Quartanion();

	~Quartanion();

	/**
	 * @brief �C�ӎ��ŔC�ӊp��]��\���N�I�[�^�j�I��
	 * @param[in]	angle	��]�p(�P��:radian)
	 * @param[in]	axis	��]��(���K���ς�)
	 * @return		��]��\���N�I�[�^�j�I��
	 */
	QuartanionElement CalculateRotateQuartanion(float angle, VEC3 axis);

	/**
	 * @brief �C�ӎ��ŔC�ӊp��]��\�������N�I�[�^�j�I��
	 * @param[in]	angle	��]�p(�P��:radian)
	 * @param[in]	axis	��]��(���K���ς�)
	 * @return		��]��\�������N�I�[�^�j�I��
	 */
	QuartanionElement CalculateConjuRotateQuartanion(float angle, VEC3 axis);

	/**
	 * @brief �C�ӂ̃x�N�g�����A�N�I�[�^�j�I���ō��W�ϊ�
	 * @param[in]	inputVec	�ϊ��������x�N�g��
	 * @param[in]	quartanion	�N�I�[�^�j�I��
	 * @param[in]	quartanion	�����N�I�[�^�j�I��
	 * @return		�ϊ��ς݃N�I�[�^�j�I��
	 */
	VEC3 AttatchQuartanion(VEC3 inputVec, QuartanionElement quartanion, QuartanionElement conjuQuartanion);
};

/**
* @brief �C�ӂ̃x�N�g�����A�N�I�[�^�j�I���̊|���Z
* @param[in]	q1	�N�I�[�^�j�I��1
* @param[in]	q2	�N�I�[�^�j�I��2
* @return	�N�I�[�^�j�I���̊|���Z����
*/
QuartanionElement MultQuartanion(QuartanionElement q1, QuartanionElement q2);

/**
* @brief ����
* @param[in]	v1	�x�N�g��1
* @param[in]	v2	�x�N�g��2
* @return	���ό���
*/
double Dot(VEC3 v1, VEC3 v2);

/**
* @brief �O��
* @param[in]	v1	�x�N�g��1
* @param[in]	v2	�x�N�g��2
* @return	�O�ό���
*/
VEC3 Cross(VEC3 v1, VEC3 v2);

/**
* @brief �X�J���[�ƃx�N�g���̐�
* @param[in]	d	�X�J���[
* @param[in]	v	�x�N�g��
* @return	�X�J���[�ƃx�N�g���̐�
*/
VEC3 MultVec3(double d, VEC3 v);

#endif // _QUARTANION
