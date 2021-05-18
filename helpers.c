#include "helpers.h"
#include<math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int av = 0;
    //i = height is, j = width js
    for(int i = 0; i < height; i++){

        for(int j = 0; j< width; j++){

            av = ceil((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3);
            image[i][j].rgbtRed = av;
            image[i][j].rgbtGreen = av;
            image[i][j].rgbtBlue = av;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{


     for(int i = 0; i < height; i++){

        for(int j = 0; j< width; j++){
            RGBTRIPLE sepia;
            int originalRed = image[i][j].rgbtRed, originalBlue = image[i][j].rgbtBlue, originalGreen = image[i][j].rgbtGreen;
             sepia.rgbtRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepia.rgbtGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
             sepia.rgbtBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if(sepia.rgbtRed > 255){
                image[i][j].rgbtRed = 255;
            }
            else{
               image[i][j].rgbtRed = sepia.rgbtRed;
            }
             if(sepia.rgbtGreen > 255){
                image[i][j].rgbtGreen = 255;
            }
            else{
                image[i][j].rgbtGreen = sepia.rgbtGreen;
            }
             if(sepia.rgbtBlue > 255){
                image[i][j].rgbtBlue = 255;
            }
            else{
                image[i][j].rgbtBlue = sepia.rgbtBlue;
            }


            }

        }

    return;
}
void swap(RGBTRIPLE *p1, RGBTRIPLE *p2){

    RGBTRIPLE tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;

}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i<height; i++){
        for(int j = 0; j < width/2 ; j++){

            swap(&image[i][j],& image[i][width - 1 - j]);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{


        int avR, avG, avB, count;

    RGBTRIPLE copy[height][width];

        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                copy[h][w] = image[h][w];
            }
        }


        for (int lin = 0; lin < height; lin++)
        {
            for (int com = 0; com < width; com++)
            {
                // initialize
                avR = 0;
                avG = 0;
                avB = 0;
                count = 0;

                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if (lin + i < 0 || com + j < 0 || lin + i >= height || com + j >= width)
                        {

                        }
                        else
                        {
                            avR += copy[lin + i][com + j].rgbtRed;
                            avG += copy[lin + i][com + j].rgbtGreen;
                            avB += copy[lin + i][com + j].rgbtBlue;
                            count++;
                        }
                    }
                }
                image[lin][com].rgbtRed = round(avR / (float) count);
                image[lin][com].rgbtGreen = round(avG / (float) count);
                image[lin][com].rgbtBlue = round(avB / (float) count);
            }
        }

    return;
}
