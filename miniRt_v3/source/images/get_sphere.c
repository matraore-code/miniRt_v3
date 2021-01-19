#include "../../includes/minirt.h"

void swap_d(double *d1, double *d2)
{
    double tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

static double	tuple_angle(t_tuple vec1, t_tuple vec2)
{
	double	res;

	res = dot_tuple(vec1, vec2);
	res /= longueur_tuple(vec1) * longueur_tuple(vec2);
	res = acos(res);
	return (res);
}

t_tuple	adjust_normal(t_tuple ray, t_tuple norm)
{
	if (tuple_angle(norm, ray) < Pi)
		return (scale_tuple(-1, norm));
	return (norm);
}

t_tuple normale_sphere(t_hit hit, t_ray ray, t_data *g_win)
{
        t_tuple tuple;
    
        tuple = normalize_tuple(sub_tuple(hit.obj->pos[0], hit.pos));
        return (adjust_normal(ray.dir, tuple));
}

t_hit   get_hit_sphere(t_object *sphere, t_ray ray, t_data *g_win)
{
    double t[3];
    double tc[2];
    double dis;
    t_tuple p;

    (void)g_win;
    p = sub_tuple(sphere->pos[0], ray.ori);
    tc[0] = dot_tuple(p, ray.dir);
    dis = dot_tuple(p, p) - pow(tc[0], 2);
    if (dis > sphere->size / 2)
    {
        return (hit_infini());
    }
    tc[1] = sqrt(sphere->size / 2  - dis);
    t[0] = tc[0] - tc[1];
    t[1] = tc[0] + tc[1];
    if (t[0] > t[1])
        swap_d(&t[0], &t[1]);
    if (t[0] < 0)
    {
        t[0] = t[1];
        if (t[0] < 0)
            return (hit_infini());
    }
    return (create_dist_hit(sphere, add_tuple(ray.ori, scale_tuple(t[0], ray.dir)), sphere->color, t[0]));
}
