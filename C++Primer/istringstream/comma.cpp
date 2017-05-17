#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

int comma()
{
  gStyle->SetOptStat(0);
  // gStyle->SetOptTitle(0);
  c1 = new TCanvas("c1", "c1", 1200, 700);
  // c1->SetLogx();
  
  gPad->SetTickx();  
  gPad->SetTicky();
  gPad->SetBottomMargin(0.12);
  gPad->SetLeftMargin(0.12);


  const unsigned int ROW  = 200000;
  ifstream input("./shot2V1730B.txt");
  if (!input)
    {
      cerr << "open cerr !!!" << endl;
      return 0;
    }
  int effectiveRow = 0;
  double column0[ROW], column1[ROW], column2[ROW], column3[ROW];
  string line;
  /// read the first line
  getline(input, line);
  for(unsigned i = 0; getline(input, line); ++i)
    {
      if(!input.good())break;
      istringstream iss(line);
      string col;
      double lineValue[4];
      for(unsigned j = 0; getline(iss, col, ','); ++j)
        {
          lineValue[j] = stod(col);
        }
      column0[i] = lineValue[0];
      column1[i] = lineValue[1];
      column2[i] = lineValue[2];
      column3[i] = lineValue[3];
      ++effectiveRow;
    }
  input.close();

  TGraph *grinB = new TGraph(effectiveRow, column0, column1);
  grinB->Draw();
  grinB->SetTitle("");
  // grinB->GetXaxis()->SetRangeUser(0,8000);
  //grinB->GetYaxis()->SetRangeUser(-2,115);
  grinB->GetXaxis()->CenterTitle(true);
  grinB->GetXaxis()->SetLabelFont(42);
  grinB->GetXaxis()->SetLabelSize(0.05);
  grinB->GetXaxis()->SetTitleSize(0.05);
  grinB->GetXaxis()->SetTitleOffset(1.1);
  grinB->GetXaxis()->SetTitleFont(42);
  grinB->GetYaxis()->CenterTitle(true);
  grinB->GetYaxis()->SetLabelFont(42);
  grinB->GetYaxis()->SetLabelSize(0.05);
  grinB->GetYaxis()->SetTitleSize(0.05);
  grinB->GetYaxis()->SetTitleOffset(1.1);
  grinB->GetYaxis()->SetTitleFont(42);
  grinB->GetXaxis()->SetTitle("Energy(keV)");
  grinB->GetYaxis()->SetTitle("Efficiency(%)");
  grinB->SetMarkerStyle(20);
  grinB->SetMarkerColor(kBlack);
  grinB->SetLineColor(kBlack);
      
  grinB->Draw("");
    
  TF1 *fal = new TF1("fal","exp(-x)",0,300);
  fal->Draw("same");
    
   TLegend *leg = new TLegend(0.4457429,0.2707101,0.7462437,0.4497041,NULL,"brNDC");
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->AddEntry(grinB,"^{6+}Carbon","lp");
  // leg->AddEntry(grin,"Alpha","lp");
  //leg->AddEntry(grinC,"Electron","lp");
  //leg->AddEntry(grinD,"Gamma","lp");   
  //leg->AddEntry(grinE,"Proton","lp"); 
  leg->Draw();  
  
  return 0;
}

