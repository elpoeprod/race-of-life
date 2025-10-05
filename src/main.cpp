#define GB_USE_SMALL_FUNCNAMES
#include <gamebreaker/gamebreaker.hpp>
namespace gb=GameBreaker;

GBObject *player=nullptr;
GBSprite 	*sprBaby,*sprChild,*sprSmallKid,*sprKid,*sprBigKid,*sprBoy,*sprBigBoy,*sprYouth,*sprBigYouth,
			*sprYoungAdult,*sprAdult,*sprYoungMan,*sprMan,*sprMatureMan,*sprOldMan,*sprOlderMan,*sprVeryOldMan,
			*sprGeezer,*sprOldGeezer,*sprWheelChair,*sprBed,*sprGrave;

GBSound	*mysong=nullptr;

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
	if(mouse::pressed(mb::left)) self->spd+=0.58;
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

	self->image_index+=self->spd*0.1;
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

void player_draw(GBObject *self) {
	draw::sprite(self->spr,self->image_index,self->x,self->y,1,1,0);
}

GBRoom *myroom;

int main() {
	gb::init(GB_WINPOS_CENTER,GB_WINPOS_CENTER,"Race of Life");

	sprBaby=		sprite::add("sprites/sprBaby.png",2,0,0);
	sprChild=		sprite::add("sprites/sprChild.png",4,0,0);
	sprSmallKid=	sprite::add("sprites/sprSmallKid.png",2,0,0);
	sprKid=			sprite::add("sprites/sprKid.png",2,0,0);
	sprBigKid=		sprite::add("sprites/sprBigKid.png",2,0,0);
	sprBoy=			sprite::add("sprites/sprBoy.png",2,0,0);
	sprBigBoy=		sprite::add("sprites/sprBigBoy.png",2,0,0);
	sprYouth=		sprite::add("sprites/sprYouth.png",2,0,0);
	sprBigYouth=	sprite::add("sprites/sprBigYouth.png",2,0,0);
	sprYoungAdult=	sprite::add("sprites/sprYoungAdult.png",2,0,0);
	sprAdult=		sprite::add("sprites/sprAdult.png",2,0,0);
	sprYoungMan=	sprite::add("sprites/sprYoungMan.png",2,0,0);
	sprMan=			sprite::add("sprites/sprMan.png",2,0,0);
	sprMatureMan=	sprite::add("sprites/sprMatureMan.png",2,0,0);
	sprOldMan=		sprite::add("sprites/sprOldMan.png",2,0,0);
	sprOlderMan=	sprite::add("sprites/sprOlderMan.png",2,0,0);
	sprVeryOldMan=	sprite::add("sprites/sprVeryOldMan.png",2,0,0);
	sprGeezer=		sprite::add("sprites/sprGeezer.png",2,0,0);
	sprOldGeezer=	sprite::add("sprites/sprOldGeezer.png",2,0,0);
	sprWheelChair=	sprite::add("sprites/sprWheelChair.png",2,0,0);
	sprBed=			sprite::add("sprites/sprBed.png",2,0,0);
	sprGrave=		sprite::add("sprites/sprGrave.png",2,0,0);
	
	player=object::add(nullptr,nullptr);
	
	mysong=audio::add("hzcanhaa.xm",gb::GB_MUSIC);
	if(mysong==nullptr) exit(0x0000);
	audio::loop(mysong,-1);
	
	player->event_create=player_create;
	player->event_step=player_step;
	player->event_draw=player_draw;
	
	myroom=room::add(640,480);
	room::add_instance(myroom,player,-4,240,nullptr);
	room::current(myroom);
	
	gb::run();
	gb::shutdown();
	return 0;
}
