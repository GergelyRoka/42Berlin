#include <stdio.h>
#include <math.h>
#include "../../include/tuples.h"


/*
Try playing with this little program, firing virtual projectiles and seeing how
far they go. It’ll let you exercise the vector and point routines you’ve written.
Start with the following two data structures:
• A projectile has a position (a point) and a velocity (a vector).
• An environment has gravity (a vector) and wind (a vector).
Then, add a tick(environment, projectile) function which returns a new projectile,
representing  the  given  projectile  after  one  unit  of  time  has  passed.  (The
actual units here don’t really matter—maybe they’re seconds, or milliseconds.
Whatever. We’ll just call them “ticks.”)
In pseudocode, the tick() function should do the following:
function tick(env, proj)
position ← proj.position + proj.velocity
velocity ← proj.velocity + env.gravity + env.wind
return projectile(position, velocity)
end function
Now,  initialize  a  projectile  and  an  environment.  Use  whatever  values  you
want, but these might get you started:
# projectile starts one unit above the origin.
# velocity is normalized to 1 unit/tick.
p ← projectile(point(0, 1, 0), normalize(vector(1, 1, 0)))
# gravity -0.1 unit/tick, and wind is -0.01 unit/tick.
e ← environment(vector(0, -0.1, 0), vector(-0.01, 0, 0))
Then, run tick repeatedly until the projectile’s y position is less than or equal
to 0. Report the projectile’s position after each tick, and the number of ticks
it takes for the projectile to hit the ground. Try multiplying the projectile’s
initial  velocity  by  larger  and  larger  numbers  to  see  how  much  farther  the
projectile goes!
Once you’ve had a chance to play with this virtual cannon a bit, move to the
next chapter. You’re going to implement the visual side of your ray tracer,
the canvas onto which everything will eventually be drawn.
report erratum  •  discuss
*/

typedef struct s_environment
{
	t_vector gravity;
	t_vector wind;
} t_environment;


typedef struct s_projectile
{
	t_point position;
	t_vector velocity;
} t_projectile;

t_projectile tick(t_environment env, t_projectile proj)
{
	t_projectile updated_proj;
	
	updated_proj.position = add_tuple_tuple(proj.position, proj.velocity);
	updated_proj.velocity = add_tuple_tuple(add_tuple_tuple(proj.velocity, env.gravity), env.wind);
	
	return updated_proj;
}

int main()
{
	t_environment e;
	t_projectile p;
	int tick_count = 0;
	
	e.gravity = do_vector(0, -0.1, 0);
	e.wind = do_vector(-0.01, 0, 0);
	
	p.position = do_point(0, 1, 0);
	p.velocity = normalize(do_vector(1, 1, 0));
	
	while (p.position.y > 0)
	{
		p = tick(e, p);
		printf("%f, %f, %f\n", p.position.x, p.position.y, p.position.z);
		tick_count++;
	}
	
	printf("Number of ticks to hit the ground: %d\n", tick_count);
	
	return 0;
}


