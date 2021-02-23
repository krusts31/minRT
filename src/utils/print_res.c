#include "parcer.h"
#include "minRT.h"
#include <stdio.h>

void	print_res(t_task *task)
{
	int		index;

	index = 0;
	printf("************************************************************\n");
	printf("******************RESULUTIO*********************************\n");
	printf("************************************************************\n");
	printf("this is X_res %zu\n", task->X_res);
	printf("this is Y_res %zu\n", task->Y_res);
	if (task->Amb_light)
	{
		printf("************************************************************\n");
		printf("******************AMB_light*********************************\n");
		printf("************************************************************\n");
		printf("this is rartio %f\n", task->Amb_light->ratio);
		printf("this is r %d\n", task->Amb_light->col->e[0]);
		printf("this is g %d\n", task->Amb_light->col->e[1]);
		printf("this is b %d\n", task->Amb_light->col->e[2]);
	}
	else
		printf("Amb failed\n");
	if (task->camera)
	{
		printf("************************************************************\n");
		printf("******************CAMERA************************************\n");
		printf("************************************************************\n");
		index = 0;
		while (task->camera != NULL)
		{
			printf("this is cor->e[0] %f for camera %d\n", task->camera->cor->e[0], index);
			printf("this is cor->e[1] %f for camera %d\n", task->camera->cor->e[1], index);
			printf("this is cor->e[2] %f for camera %d\n", task->camera->cor->e[2], index);
			printf("this is norm->e[0] %f for camera %d\n", task->camera->norm->e[0], index);
			printf("this is norm->e[1] %f for camera %d\n", task->camera->norm->e[1], index);
			printf("this is norm->e[2] %f for camera %d\n", task->camera->norm->e[2], index);
			printf("this is FOV %f for camera %d\n", task->camera->FOV, index);
			task->camera = task->camera->next;
			index++;
		}
	}
	else
		printf("cam failed\n");
	if (task->light)
	{
		printf("************************************************************\n");
		printf("******************LIGHT*************************************\n");
		printf("************************************************************\n");
		index = 0;
		while (task->light != NULL)
		{
			printf("this is cor->e[0] %f for light %d\n", task->light->cor->e[0], index);
			printf("this is cor->e[1] %f for light %d\n", task->light->cor->e[1], index);
			printf("this is cor->e[2] %f for light %d\n", task->light->cor->e[2], index);
			printf("this is norm->e[0] %d for light %d\n", task->light->col->e[0], index);
			printf("this is norm->e[1] %d for light %d\n", task->light->col->e[1], index);
			printf("this is norm->e[2] %d for light %d\n", task->light->col->e[2], index);
			printf("this is ratio %f for light %d\n", task->light->ratio, index);
			task->light = task->light->next;
			index++;
		}
	}
	else
		printf("light failed\n");
	if (task->sp)
	{
		printf("************************************************************\n");
		printf("******************SQHIER************************************\n");
		printf("************************************************************\n");
		index = 0;
		while (task->sp != NULL)
		{
			printf("this is cor->e[0] %f for sp %d\n", task->sp->cor->e[0], index);
			printf("this is cor->e[1] %f for sp %d\n", task->sp->cor->e[1], index);
			printf("this is cor->e[2] %f for sp %d\n", task->sp->cor->e[2], index);
			printf("this is col->e[0] %d for sp %d\n", task->sp->col->e[0], index);
			printf("this is col->e[1] %d for sp %d\n", task->sp->col->e[1], index);
			printf("this is col->e[2] %d for sp %d\n", task->sp->col->e[2], index);
			printf("this is ratio %f for sp %d\n", task->sp->diameter, index);
			task->sp = task->sp->next;
			index++;
		}
	}
	else
		printf("cy failed\n");
	if (task->pl)
	{
		printf("************************************************************\n");
		printf("******************PLANE*************************************\n");
		printf("************************************************************\n");
		index = 0;
		while (task->pl != NULL)
		{
			printf("this is cor->e[0] %f for pl %d\n", task->pl->cor->e[0], index);
			printf("this is cor->e[1] %f for pl %d\n", task->pl->cor->e[1], index);
			printf("this is cor->e[2] %f for pl %d\n", task->pl->cor->e[2], index);
			printf("this is cor->e[0] %f for pl %d\n", task->pl->norm->e[0], index);
			printf("this is cor->e[1] %f for pl %d\n", task->pl->norm->e[1], index);
			printf("this is cor->e[2] %f for pl %d\n", task->pl->norm->e[2], index);
			printf("this is norm->e[0] %d for pl %d\n", task->pl->col->e[0], index);
			printf("this is norm->e[1] %d for pl %d\n", task->pl->col->e[1], index);
			printf("this is norm->e[2] %d for pl %d\n", task->pl->col->e[2], index);
			task->pl = task->pl->next;
			index++;
		}
	}
	else
		printf("pl failed\n");
	if (task->sq)
	{
		printf("************************************************************\n");
		printf("******************SQUARE************************************\n");
		printf("************************************************************\n");
		index = 0;
		while (task->sq != NULL)
		{
			printf("this is cor->e[0] %f for sq %d\n", task->sq->cor->e[0], index);
			printf("this is cor->e[1] %f for sq %d\n", task->sq->cor->e[1], index);
			printf("this is cor->e[2] %f for sq %d\n", task->sq->cor->e[2], index);
			printf("this is cor->e[0] %f for sq %d\n", task->sq->norm->e[0], index);
			printf("this is cor->e[1] %f for sq %d\n", task->sq->norm->e[1], index);
			printf("this is cor->e[2] %f for sq %d\n", task->sq->norm->e[2], index);
			printf("this is norm->e[0] %d for sq %d\n", task->sq->col->e[0], index);
			printf("this is norm->e[1] %d for sq %d\n", task->sq->col->e[1], index);
			printf("this is norm->e[2] %d for sq %d\n", task->sq->col->e[2], index);
			printf("this is side_size %f for sq %d\n", task->sq->side_size, index);
			task->sq = task->sq->next;
			index++;
		}
	}
	else
		printf("sq failed\n");
	if (task->cy)
	{
		index = 0;
		printf("************************************************************\n");
		printf("******************CYLINDER**********************************\n");
		printf("************************************************************\n");
		while (task->cy != NULL)
		{
			printf("this is cor->e[0] %f for cy %d\n", task->cy->cor->e[0], index);
			printf("this is cor->e[1] %f for cy %d\n", task->cy->cor->e[1], index);
			printf("this is cor->e[2] %f for cy %d\n", task->cy->cor->e[2], index);
			printf("this is norm->e[0] %f for cy %d\n", task->cy->norm->e[0], index);
			printf("this is norm->e[1] %f for cy %d\n", task->cy->norm->e[1], index);
			printf("this is norm->e[2] %f for cy %d\n", task->cy->norm->e[2], index);
			printf("this is diameter %f for cy %d\n", task->cy->diameter, index);
			printf("this is height %f for cy %d\n", task->cy->height, index);
			printf("this is r  %d for cy %d\n", task->cy->col->e[0], index);
			printf("this is g  %d for cy %d\n", task->cy->col->e[1], index);
			printf("this is b  %d for cy %d\n", task->cy->col->e[2], index);
			task->cy = task->cy->next;
			index++;
		}
	}
	else
		printf("cy failed\n");
	if (task->tr)
	{
		printf("************************************************************\n");
		printf("******************TRINAGLE**********************************\n");
		printf("************************************************************\n");
		index = 0;
		while (task->tr != NULL)
		{
			printf("this is cor->e[0]1 %f for tr %d\n", task->tr->cor1->e[0], index);
			printf("this is cor->e[1]1 %f for tr %d\n", task->tr->cor1->e[1], index);
			printf("this is cor->e[2]1 %f for tr %d\n", task->tr->cor1->e[2], index);
			printf("this is cor->e[0]2 %f for tr %d\n", task->tr->cor2->e[0], index);
			printf("this is cor->e[1]2 %f for tr %d\n", task->tr->cor2->e[1], index);
			printf("this is cor->e[2]2 %f for tr %d\n", task->tr->cor2->e[2], index);
			printf("this is cor->e[0]3 %f for tr %d\n", task->tr->cor3->e[0], index);
			printf("this is cor->e[1]3 %f for tr %d\n", task->tr->cor3->e[1], index);
			printf("this is cor->e[2]3 %f for tr %d\n", task->tr->cor3->e[2], index);
			printf("this is norm->e[0] %d for tr %d\n", task->tr->col->e[0], index);
			printf("this is norm->e[1] %d for tr %d\n", task->tr->col->e[1], index);
			printf("this is norm->e[2] %d for tr %d\n", task->tr->col->e[2], index);
			task->tr = task->tr->next;
			index++;
		}
	}
	else
		printf("tr failed\n");
}
