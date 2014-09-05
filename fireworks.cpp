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
	for(i = 0;i < 20;i++){
		sub[i].setAcceleration(0.0f,9.0f,0.0f);
		sub[i].setMass(2.0f);
		sub[i].setDamping(0.99f);
	}
	//set submunition velocitys individualy to a default
	if(def){
		num = 20;
		for(i = 0;i < 20;i++){
				setParticle(i,(rand() % 15 + (-5)),(rand() % 15 + (-5)),1,1.0f,1.0f,0.0f);
		}
	}	
	if(num > 20)num = 20;
	for(i = 0;i < num;i++){
		//ran = (rand() % 3) + 1;
		//std::cout << ran << "\n";
		particles[index + i] = sub[i];
		particles[index + i].alive = true;
		particles[index + i].setPosition(position.x,position.y,0.0f);
	}
	return index + num;	
}
int Firework::setParticle(int part,int x_vel,int y_vel,int size,float r,float g,float b){
	sub[part].setVelocity(voxel::Vec3(x_vel,y_vel,0.0f));
	sub[part].size = size;
	sub[part].red = r;
	sub[part].green = g;
	sub[part].blue = b;
}
