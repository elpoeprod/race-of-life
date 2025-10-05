#define GB_USE_SMALL_FUNCNAMES
#include <gamebreaker/gamebreaker.hpp>
namespace gb=GameBreaker;

GBObject *player, *game_title, *grave, *gameover, *ender;
GBSprite 	*sprBaby,*sprChild,*sprSmallKid,*sprKid,*sprBigKid,*sprBoy,*sprBigBoy,*sprYouth,*sprBigYouth,
			*sprYoungAdult,*sprAdult,*sprYoungMan,*sprMan,*sprMatureMan,*sprOldMan,*sprOlderMan,*sprVeryOldMan,
			*sprGeezer,*sprOldGeezer,*sprWheelChair,*sprBed,*sprGrave;

GBSound	*mysong;

void player_create(GBObject *self) {
	self->x=-4;
	self->friction=0.1;
	self->image_speed=0;
	return;
}

int globaltime=498124981;
int globalwin=0;

int mytime=0;
int start=0;

void player_step(GBObject *self) {
	if(mouse::pressed(mb::left)) self->hspd+=0.58;
	self->spr=sprBaby;
	if(self->x>16) self->spr=sprBaby;
	if(self->x>32) self->spr=sprSmallKid;
	if(self->x>48) self->spr=sprKid;
	if(self->x>64) self->spr=sprBigKid;
	if(self->x>80) self->spr=sprBoy;
	if(self->x>96) self->spr=sprBigBoy;
	if(self->x>112) self->spr=sprYouth;
	if(self->x>128) self->spr=sprBigYouth;
	if(self->x>144) self->spr=sprYoungAdult;
	if(self->x>160) self->spr=sprAdult;
	if(self->x>176) self->spr=sprYoungMan;
	if(self->x>208) self->spr=sprMan;
	if(self->x>256) self->spr=sprMatureMan;
	if(self->x>320) self->spr=sprOldMan;
	if(self->x>352) self->spr=sprOlderMan;
	if(self->x>384) self->spr=sprVeryOldMan;
	if(self->x>416) self->spr=sprGeezer;
	if(self->x>432) self->spr=sprOldGeezer;
	if(self->x>448) self->spr=sprWheelChair;
	if(self->x>464) self->spr=sprBed;

	self->image_index+=self->hspd*0.1;
	if(self->x<484) mytime++; else {
		if(start==0) {
			if(mytime<globaltime) {
				globaltime=mytime; 
				globalwin=1;
			} else 
				globalwin=0; 
			start=1;
		}
	}
	return;
}

GBRoom *myroom;

int main() {
	gb::init(GB_WINPOS_CENTER,GB_WINPOS_CENTER,"Race of Life");

	GBObject *player=object::add(nullptr,nullptr);
	myroom=room::add(640,480);
	room::add_instance(myroom,player,-4,240,nullptr);
	room::current(myroom);
	
	gb::run();
	gb::shutdown();
	return 0;
}
