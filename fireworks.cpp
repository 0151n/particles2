//fireworks class
#include<demo/fireworks.h>
int Firework::update(float par1){
	integrate(0.1f);
	if(age >= fuse){
		alive = false;
		return 1;
	}
	age++;
	return 0;
	}
int Firework::explode(voxel::Particle *particles, int index,bool def,int num){
	int i = 0;
	//int ran;
	for(i = 0;i < 10;i++){
		sub[i].setAcceleration(0.0f,9.0f,0.0f);
		sub[i].setMass(2.0f);
		sub[i].setDamping(0.99f);
	}
	//set submunition velocitys individualy to a default
	if(def){
		num = 8;
		sub[0].setVelocity(0.0f,5.0f,0.0f);
		sub[1].setVelocity(5.0f,5.0f,0.0f);	
		sub[2].setVelocity(5.0f,0.0f,0.0f);
		sub[3].setVelocity(5.0f,-5.0f,0.0f);
		sub[4].setVelocity(0.0f,-5.0f,0.0f);
		sub[5].setVelocity(-5.0f,-5.0f,0.0f);
		sub[6].setVelocity(-5.0f,0.0f,0.0f);
		sub[7].setVelocity(-5.0f,5.0f,0.0f);
		sub[8].setVelocity(0.0f,0.0f,0.0f);
		sub[9].setVelocity(0.0f,0.0f,0.0f);
	}	
	if(num > 10)num = 10;
	for(i = 0;i < num;i++){
		//ran = (rand() % 3) + 1;
		//std::cout << ran << "\n";
		particles[index + i] = sub[i];
		particles[index + i].alive = true;
		particles[index + i].setPosition(position.x,position.y,0.0f);
	}
	return index + num;	
}
