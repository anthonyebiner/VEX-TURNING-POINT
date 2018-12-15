#include "declareStuff.hpp"

static lv_res_t btn_click_action(lv_obj_t * btn)
{
    uint8_t id = lv_obj_get_free_num(btn);

    printf("Button %d is released\n", id);

    if(id == 1){
      MasterC.print(0,0,"RED",NULL);
      autonColor = 1;
    }else if(id == 2){
      MasterC.print(0,0,"BLUE",NULL);
      autonColor = 2;
    }else if(id == 3){
      MasterC.print(0,0,"FRONT",NULL);
      autonSide = 1;
    }else if(id == 4){
      MasterC.print(0,0,"BACK",NULL);
      autonSide = 2;
    }else if(id == 5){
      MasterC.print(0,0,"1",NULL);
      autonNumber = 1;
    }else if(id == 6){
      MasterC.print(0,0,"2",NULL);
      autonNumber = 2;
    }

    return LV_RES_OK; /*Return OK if the button is not deleted*/
}


void initGraphics() {
  /*Create a title label*/
  lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_text(label, "Color");
  lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_LEFT, 50, 5);

  /*Create a normal button*/
  lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
  lv_cont_set_fit(btn1, true, true); /*Enable resizing horizontally and vertically*/
  lv_obj_align(btn1, label, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_free_num(btn1, 1);   /*Set a unique number for the button*/
  lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_click_action);

  /*Add a label to the button*/
  label = lv_label_create(btn1, NULL);
  lv_label_set_text(label, "Red");

  /*Copy the button and set toggled state. (The release action is copied too)*/
  lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), btn1);
  lv_obj_align(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_free_num(btn2, 2);               /*Set a unique number for the button*/

  /*Add a label to the toggled button*/
  label = lv_label_create(btn2, NULL);
  lv_label_set_text(label, "Blue");



  /*Create a title label*/
  lv_obj_t * label2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_text(label2, "Side");
  lv_obj_align(label2, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

  /*Create a normal button*/
  lv_obj_t * btn3 = lv_btn_create(lv_scr_act(), NULL);
  lv_cont_set_fit(btn3, true, true); /*Enable resizing horizontally and vertically*/
  lv_obj_align(btn3, label2, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_free_num(btn3, 3);   /*Set a unique number for the button*/
  lv_btn_set_action(btn3, LV_BTN_ACTION_CLICK, btn_click_action);

  /*Add a label to the button*/
  label = lv_label_create(btn3, NULL);
  lv_label_set_text(label, "Front");

  /*Copy the button and set toggled state. (The release action is copied too)*/
  lv_obj_t * btn4 = lv_btn_create(lv_scr_act(), btn3);
  lv_obj_align(btn4, btn3, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_free_num(btn4, 4);               /*Set a unique number for the button*/

  /*Add a label to the toggled button*/
  label = lv_label_create(btn4, NULL);
  lv_label_set_text(label, "Back");




  /*Create a title label*/
  lv_obj_t * label3 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_text(label3, "NUMBER");
  lv_obj_align(label3, NULL, LV_ALIGN_IN_TOP_RIGHT, -50, 5);

  /*Create a normal button*/
  lv_obj_t * btn5 = lv_btn_create(lv_scr_act(), NULL);
  lv_cont_set_fit(btn5, true, true); /*Enable resizing horizontally and vertically*/
  lv_obj_align(btn5, label3, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_free_num(btn5, 5);   /*Set a unique number for the button*/
  lv_btn_set_action(btn5, LV_BTN_ACTION_CLICK, btn_click_action);

  /*Add a label to the button*/
  label = lv_label_create(btn5, NULL);
  lv_label_set_text(label, "1");

  /*Copy the button and set toggled state. (The release action is copied too)*/
  lv_obj_t * btn6 = lv_btn_create(lv_scr_act(), btn5);
  lv_obj_align(btn6, btn5, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
  lv_obj_set_free_num(btn6, 4);               /*Set a unique number for the button*/

  /*Add a label to the toggled button*/
  label = lv_label_create(btn6, NULL);
  lv_label_set_text(label, "2");
}
