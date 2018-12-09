#include "declareStuff.hpp"
Motor FrontRightM(1, MOTOR_GEARSET_18, true, MOTOR_ENCODER_DEGREES);
Motor FrontLeftM(2, MOTOR_GEARSET_18, false, MOTOR_ENCODER_DEGREES);
Motor BackRightM(3, MOTOR_GEARSET_36, true, MOTOR_ENCODER_DEGREES);
Motor BackLeftM(4, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor IntakeM(5, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor LiftM(6, MOTOR_GEARSET_36, false, MOTOR_ENCODER_DEGREES);
Motor Flywheel1M(7, MOTOR_GEARSET_6, true, MOTOR_ENCODER_DEGREES);
Motor Flywheel2M(8, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);

Vision VisionSensor(9);

Controller MasterC(CONTROLLER_MASTER);
Controller PartnerC(CONTROLLER_PARTNER);

int frontWheelDiameter = 6;
int backWheelDiameter = 8;

int midFlagHeight = 28;
int visionHeight = 11;
int FOV = 47;

int centerShotTolerance = 5;
int kp = 1;

int distanceSeperation = 10; //inches
int highVelocities [10] = {10,15,20,25,30,35,40,45,50,55}; //fill these in
int midVelocities [10] = {5,10,15,20,25,30,35,40,45,50}; //fill these in

/*Called when a button is released ot long pressed*/
static lv_res_t btnm_action(lv_obj_t * btnm, const char *txt)
{
    printf("Button: %s released\n", txt);

    return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}

void initialize() {
	resetPositions();
	Flywheel1M.set_brake_mode(MOTOR_BRAKE_COAST);
	Flywheel2M.set_brake_mode(MOTOR_BRAKE_COAST);
	IntakeM.set_brake_mode(MOTOR_BRAKE_BRAKE);
	LiftM.set_brake_mode(MOTOR_BRAKE_HOLD);
	FrontLeftM.set_brake_mode(MOTOR_BRAKE_HOLD);
	FrontRightM.set_brake_mode(MOTOR_BRAKE_HOLD);
	BackRightM.set_brake_mode(MOTOR_BRAKE_HOLD);
	BackLeftM.set_brake_mode(MOTOR_BRAKE_HOLD);

	/*Create a button descriptor string array*/
	static const char * btnm_map[] = {"1", "2", "3", "4", "\n", "5", "6", "7", "8",""};

	/*Create a default button matrix*/
	lv_obj_t * btnm1 = lv_btnm_create(lv_scr_act(), NULL);
	lv_btnm_set_map(btnm1, btnm_map);
	lv_btnm_set_action(btnm1, btnm_action);
	lv_obj_set_size(btnm1, LV_HOR_RES, LV_VER_RES / 2);

	/*Create a new style for the button matrix back ground*/
	static lv_style_t style_bg;
	lv_style_copy(&style_bg, &lv_style_plain);
	style_bg.body.main_color = LV_COLOR_SILVER;
	style_bg.body.grad_color = LV_COLOR_SILVER;
	style_bg.body.padding.hor = 0;
	style_bg.body.padding.ver = 0;
	style_bg.body.padding.inner = 0;

	/*Create 2 button styles*/
	static lv_style_t style_btn_rel;
	static lv_style_t style_btn_pr;
	lv_style_copy(&style_btn_rel, &lv_style_btn_rel);
	style_btn_rel.body.main_color = LV_COLOR_MAKE(0x30, 0x30, 0x30);
	style_btn_rel.body.grad_color = LV_COLOR_BLACK;
	style_btn_rel.body.border.color = LV_COLOR_SILVER;
	style_btn_rel.body.border.width = 1;
	style_btn_rel.body.border.opa = LV_OPA_50;
	style_btn_rel.body.radius = 0;

	lv_style_copy(&style_btn_pr, &style_btn_rel);
	style_btn_pr.body.main_color = LV_COLOR_MAKE(0x55, 0x96, 0xd8);
	style_btn_pr.body.grad_color = LV_COLOR_MAKE(0x37, 0x62, 0x90);
	style_btn_pr.text.color = LV_COLOR_MAKE(0xbb, 0xd5, 0xf1);

	/*Create a second button matrix with the new styles*/
	lv_obj_t * btnm2 = lv_btnm_create(lv_scr_act(), btnm1);
	lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BG, &style_bg);
	lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BTN_REL, &style_btn_rel);
	lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BTN_PR, &style_btn_pr);
	lv_obj_align(btnm2, btnm1, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}

void disabled() {

}

void competition_initialize() {

}
