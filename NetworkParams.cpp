#include "NetworkParams.h"
#include <random>

NetworkParams::NetworkParams()
{
}

NetworkParams::NetworkParams(Params* params)
{
	hiddenLayers = params->hiddenLayers;
	hiddenNodes = params->hiddenNodes;
	maxWeight = params->maxWeight;
	inputNodes = params->inputNodes;
	outputNodes = params->outputNodes;

	// initialize weights with 0
	weightArray = new float**[hiddenLayers - 1];
	for(int j = 0; j < hiddenLayers - 1; j++)
	{
		weightArray[j] = new float*[hiddenNodes];
		for(int k = 0; k < hiddenNodes; k++)
		{
			weightArray[j][k] = new float[hiddenNodes];
			for(int l = 0; l < hiddenNodes; l++)
			{
				weightArray[j][k][l] = (float)(rand() % (int)pow((float)10, PRECISION)) * maxWeight * 2 / pow((float)10, PRECISION) - maxWeight;
			}
		}
	}

	inputWeightArray = new float*[inputNodes];
	for(int j = 0; j < inputNodes; j++)
	{
		inputWeightArray[j] = new float[hiddenNodes];
		for(int k = 0; k < hiddenNodes; k++)
		{
			inputWeightArray[j][k] = (float)(rand() % (int)pow((float)10, PRECISION)) * maxWeight * 2 / pow((float)10, PRECISION) - maxWeight;
		}
	}

	outputWeightArray = new float*[hiddenNodes];
	for(int j = 0; j < hiddenNodes; j++)
	{
		outputWeightArray[j] = new float[outputNodes];
		for(int k = 0; k < outputNodes; k++)
		{
			outputWeightArray[j][k] = (float)(rand() % (int)pow((float)10, PRECISION)) * maxWeight * 2 / pow((float)10, PRECISION) - maxWeight;
		}
	}
}


NetworkParams::~NetworkParams(void)
{
	for(int i = 0; i < hiddenLayers - 1; i++)
	{
		for(int j = 0; j < hiddenNodes; j++)
		{
			delete[] weightArray[i][j];
		}
		delete[] weightArray[i];
	}
	delete[] weightArray;
}
