#pragma once
#include "types.hpp"

#define LEARNING_RATE 0.01
#define MOMENTUM 0.6
#define WEIGHT_DECAY 0.001

static double update_weight( double w, gradient_t& grad, double multp = 1 )
{
	double m = (grad.grad + grad.oldgrad * MOMENTUM);
	w -= LEARNING_RATE * m * multp + LEARNING_RATE * WEIGHT_DECAY * w;
	return w;
}

static void update_gradient( gradient_t& grad )
{
	grad.oldgrad = (grad.grad + grad.oldgrad * MOMENTUM);
}
