int main() {
  //std::ofstream ofile; //ofile.open(skinFileName);
  //std::freopen (skinFileName.c_str(),"w",stdout);
  FILE* oFile = fopen(skinFileName.c_str(), "w");


  //ofile << xCoord << ' ' << yCoord << ' ' << rezZ[i][j] << std::endl;
  //printf("%lf %lf %lf\n", xCoord, yCoord, rezZ[i][j]);
  fprintf(oFile, "%lf %lf %lf\n", xCoord, yCoord, rezZ[i][j]);

  //ofile.close();
  //std::fclose (stdout);
  fclose(oFile);
}