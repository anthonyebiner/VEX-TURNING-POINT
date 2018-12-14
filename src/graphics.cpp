#include "declareStuff.hpp"

/*Called when a button is released or long pressed*/
static lv_res_t btnm_action(lv_obj_t * btnm, const char *txt)
{/*
    if(txt == "Red Front 1"){
      auton = 1;
    }else if(txt == "Red Front 2"){
      auton = 2;
    }else if(txt == "Red Back 1"){
      auton = 3;
    }else if(txt == "Red Back 2"){
      auton = 4;
    }else if(txt == "Blue Front 1"){
      auton = 5;
    }else if(txt == "Blue Front 2"){
      auton = 6;
    }else if(txt == "Blue Back 1"){
      auton = 7
    }else if(txt == "Blue Back 2"){
      auton = 8;
    }
*/
    return LV_RES_OK; /*Return OK because the button matrix is not deleted*/
}

void initGraphics() {
	/*Create a button descriptor string array*/
	static const char * btnm_map[] = {"Red Front 1", "Red Front 2", "Red Back 1", "Red Back 2", "\n", "Blue Front 1", "Blue Front 2", "Blue Back 1", "Blue Back 2",""};

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
	lv_obj_t * btnm2 = lv_btnm_create(lv_scr_act(), NULL);
	lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BG, &style_bg);
	lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BTN_REL, &style_btn_rel);
	lv_btnm_set_style(btnm2, LV_BTNM_STYLE_BTN_PR, &style_btn_pr);
  lv_btnm_set_map(btnm2, btnm_map);
  lv_btnm_set_action(btnm2, btnm_action);
  lv_obj_set_size(btnm2, LV_HOR_RES, LV_VER_RES);
}
