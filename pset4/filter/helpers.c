#include "helpers.h"
#include <math.h>

int CapAt255(int color)
{
    if (color > 255)
    {
        return 255;
    }
    else
    {
        return color;
    }
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    
    int originalRed, originalGreen, originalBlue;
    float averageRGB;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;
            
            //average the RGB values 
            averageRGB = round((originalRed +
                                   originalGreen +
                                   originalBlue) /
                                  3.0);

            image[i][j].rgbtRed = averageRGB;
            image[i][j].rgbtGreen = averageRGB;
            image[i][j].rgbtBlue = averageRGB;
        }
    }
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);

            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            sepiaRed = CapAt255(sepiaRed);
            sepiaGreen = CapAt255(sepiaGreen);
            sepiaBlue = CapAt255(sepiaBlue);

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}


// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_row[width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_row[j] = image[i][j];
        
            image[i][j].rgbtRed = temp_row[width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = temp_row[width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = temp_row[width - 1 - j].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            temp_image[h][w] = image[h][w];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixel_num = 0;
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                     
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                  
                    sumRed += temp_image[i + k][j + l].rgbtRed;
                    sumGreen += temp_image[i + k][j + l].rgbtGreen;
                    sumBlue += temp_image[i + k][j + l].rgbtBlue;
                    pixel_num++;
                }
            }

            image[i][j].rgbtRed = (int)round(sumRed / pixel_num);
            image[i][j].rgbtGreen = (int)round(sumGreen / pixel_num);
            image[i][j].rgbtBlue = (int)round(sumBlue / pixel_num);
        }
    }
}